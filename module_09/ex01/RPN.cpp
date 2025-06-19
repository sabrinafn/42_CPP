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
    int digit_count = 0;
    int operator_count = 0;
    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (i % 2 != 0) {
            if (c != ' ')
                throw std::invalid_argument("Error: invalid inverted Polish mathematical expression");
        }
        else if (isdigit(c))
            digit_count++;
        else if (OPERATORS.find(c) != std::string::npos)
            operator_count++;
        else
            throw std::invalid_argument("Error: invalid inverted Polish mathematical expression");
    }
    if (operator_count != digit_count - 1)
        throw std::invalid_argument("Error: invalid inverted Polish mathematical expression");
}

int  RPN::process(const std::string &expression) {
    parseExpression(expression);
    
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            int num = strToInt(token);
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
                case '/': numbers_stack.push(second_num / first_num);
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