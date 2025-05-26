#include "ScalarConverter.hpp"

// constructor
ScalarConverter::ScalarConverter(void) {}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

// copy assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

// destructor
ScalarConverter::~ScalarConverter(void) {}

bool ScalarConverter::ConvertToChar(std::string &literal) {
    if (literal.length() == 1) {
        return true;
    }
    return false;
}

bool ScalarConverter::ConvertToInt(std::string &literal) {
    if (literal.find('f') == std::string::npos && literal.find('.') == std::string::npos) {
        int sign = 0;
        if (literal[0] == '-')
            sign = 1;
        for (size_t i = sign; i < literal.length(); i++) {
            if (!isdigit(literal[i]))
                return false;
        }
        return true;
    }
    return false;
}

// accept a string representation of a scalar literal and
// print its corresponding values interpreted as char, int, float or double
void ScalarConverter::convert(std::string &literal) {
    
    // char 
    if (ConvertToChar(literal) == true) {
        std::cout << "char: " << static_cast<char>(literal[0]) << std::endl;
        return ;
    }

    // int 
    if (ConvertToInt(literal) == true) {
        int num = 0;
        std::stringstream ss(literal);
        ss >> num;
        std::cout << "int: " << num << std::endl;
        return ;
    }
    else {
        std::cout << "not an int" << std::endl;
    }
}