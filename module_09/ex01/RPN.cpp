#include "RPN.hpp"
 
/* CONSTRUCTORS */
RPN::RPN() : operands(), OPERATORS("+-*/") {
}

RPN::RPN(const RPN &other) {
    *this = other;
}

/* DESTRUCTOR */
RPN::~RPN() {}

/* OPERATORS */
RPN& RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->operands = other.operands;
    }
    return *this;
}

bool RPN::parseExpression(const std::string &expression) {
    // numbers 0 to 9 and operators "+ - / *"
    // validate spaces between each digit
    // number of operators = number of operands - 1
    int digit_count = 0;
    int operator_count = 0;
    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (i % 2 != 0) {
            if (c != ' ') {
                std::cerr << "Error: invalid characters in expression" << std::endl;
                return false;
            }
        }
        else if (isdigit(c))
            digit_count++;
        else if (OPERATORS.find(c) != std::string::npos)
            operator_count++;
        else {
            std::cerr << "Error: invalid characters in expression" << std::endl;
            return false;
        }
    }
    if (operator_count != digit_count - 1) {
        std::cerr << "Error: invalid characters in expression" << std::endl;
        return false;
    }
    return true;
}

int  RPN::process(const std::string &expression) {
    if (!parseExpression(expression))
        throw std::invalid_argument("Error: invalid expression");
    
    
}