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

bool ScalarConverter::IsCharLiteral(std::string &literal) {
    if (literal.length() == 1) {
        return true;
    }
    return false;
}

void ScalarConverter::ConvertCharLiteral(std::string &literal) {    
    
    std::cout << "char identified" << std::endl;
    // convert to char
    char c = '\0';
    if (isprint(literal[0])) {
        c = static_cast<char>(literal[0]);
        std::cout << "char: " << c << std::endl;
    }
    else
        std::cout << "char: Non displayable" << std::endl;
    

    // int
    int i = static_cast<int>(c);
    std::cout << "int: " << i << std::endl;

    // float
    float f = static_cast<float>(c);
    std::cout << "float: "
              << std::fixed << std::setprecision(1)
              << f << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);

    // double
    double d = static_cast<double>(c);
    std::cout << "double: "
              << std::fixed << std::setprecision(1)
              << d << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

bool ScalarConverter::IsIntLiteral(std::string &literal) {
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

void ScalarConverter::ConvertIntLiteral(std::string &literal) {    
    
    int num = 0;
    std::stringstream ss(literal);
    ss >> num;
    //std::cout << "int: " << num << std::endl;

    std::cout << "int identified" << std::endl;

    // char
    if (isprint(num)) {
        char c = static_cast<char>(num);
        std::cout << "char: " << c << std::endl;
    }
    else
        std::cout << "char: Non displayable" << std::endl;
    
    // int
    int i = static_cast<int>(literal[0]);
    std::cout << "int: " << i << std::endl;

    // float
    float f = static_cast<float>(literal[0]);
    std::cout << "float: "
              << std::fixed << std::setprecision(1)
              << f << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);

    // double
    double d = static_cast<double>(literal[0]);
    std::cout << "double: "
              << std::fixed << std::setprecision(1)
              << d << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

bool ScalarConverter::IsFloatLiteral(std::string &literal) {
    if (literal.find('f') != std::string::npos && literal.find('.') != std::string::npos) {
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
    if (IsCharLiteral(literal) == true) {
        ConvertCharLiteral(literal);
        return;
    }

    // int 
    if (IsIntLiteral(literal) == true) {
        ConvertIntLiteral(literal);
        return;
    }

    // float
    if (IsFloatLiteral(literal) == true) {

    }
}