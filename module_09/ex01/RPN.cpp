#include "RPN.hpp"
 
/* CONSTRUCTORS */
RPN::RPN() : numbers_stack(), OPERATORS("+-*/") {}

RPN::RPN(const RPN &other) { *this = other; }

/* DESTRUCTOR */
RPN::~RPN() {}

/* OPERATORS */
RPN& RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->numbers_stack = other.numbers_stack;
    }
    return *this;
}

void RPN::parseExpression(const std::string &expression) {
    // numbers 0 to 9 and operators "+ - / *"
    // validate spaces between each digit
    // number of operators = number of operands - 1

    if (expression.empty())
        throw std::invalid_argument("Error: empty input");

    std::istringstream iss(expression);
    std::string token;
    int digit_count = 0;
    int operator_count = 0;

    while (iss >> token) {
        if (token.length() == 1 && isdigit(token[0])) 
            digit_count++;
        else if (token.length() == 1 && OPERATORS.find(token[0]) != std::string::npos)
            operator_count++;
        else if (token.length() > 1 && isdigit(token[1])) 
            throw std::invalid_argument("Error: invalid number (allowed: 0 to 9)");
        else
            throw std::invalid_argument("Error: invalid character '" + std::string(1,token[0]) + "'");
    }
    if (digit_count == 0 && operator_count == 0)
        throw std::invalid_argument("Error: no operands and no operators");
    else if (digit_count == 0 && operator_count != 0)
        throw std::invalid_argument("Error: no operands");
    else if (digit_count != 0 && operator_count == 0)
        throw std::invalid_argument("Error: no operators");
    else if (operator_count != digit_count - 1)
        throw std::invalid_argument("Error: insufficient operands for operator");
}

int  RPN::process(const std::string &expression) {
    parseExpression(expression);
    
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            long num = strToInt(token);
            numbers_stack.push(num);
        }
        else {
            if (numbers_stack.size() < 2)
                throw std::invalid_argument("Error: not enough operands in stack for operator [" + token + "]");
            int first_num = numbers_stack.top();
            numbers_stack.pop();
            int second_num = numbers_stack.top();
            numbers_stack.pop();
            switch (token[0]) {
                case '+': numbers_stack.push(second_num + first_num);
                    break;
                case '-': numbers_stack.push(second_num - first_num);
                    break;
                case '*': numbers_stack.push(second_num * first_num);
                    break;
                case '/':
                    if (first_num == 0)
                        throw std::invalid_argument("Error: division by zero is not allowed");
                    numbers_stack.push(second_num / first_num);
                    break;
            }
        }
    }
    return (numbers_stack.top());
}

int RPN::strToInt(const std::string &str) const {
    std::stringstream txt_file(str);
    int i;
    txt_file >> i;
    return i;
}