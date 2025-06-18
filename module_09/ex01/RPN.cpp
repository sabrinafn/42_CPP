#include "RPN.hpp"
 
/* CONSTRUCTORS */
RPN::RPN() : operands(), OPERATORS("+-*/") {
}

RPN::RPN(const std::string &expression) : operands(), OPERATORS("+-*/") {

    if (!parseExpression(expression)) {
        throw std::invalid_argument("Error: invalid polish mathematical expression");
    }

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
    for (size_t i = 0; i < expression.length(); i++) {
        if (!isdigit(expression[i]) && !isOperator(expression[i]))
            throw std::invalid_argument("Error: invalid characters in expression");
    }
    return false;
}

bool RPN::isOperator(const char c) {

    for (size_t i = 0; i < OPERATORS.length(); i++) {
        if (OPERATORS[i] != c)
            return false;
    }
    return true;
}