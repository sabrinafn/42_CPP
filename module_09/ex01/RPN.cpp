#include "RPN.hpp"
 
/* CONSTRUCTORS */
RPN::RPN() : operands() {
}

RPN::RPN(const std::string &expression) : operands() {

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

bool parseExpression(const std::string &expression) {
    return false;
}