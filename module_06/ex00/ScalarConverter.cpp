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

    if (literal.length() == 1 && !isdigit(literal[0])) {
        return true;
    }
    else if (literal.length() == 3 && literal[0] == '\''
            && literal[2] == '\'' && !isdigit(literal[1])) {
            return true;
    }
    return false;
}

void ScalarConverter::ConvertCharLiteral(std::string &literal) {    
    
    std::cout << "char identified" << std::endl;

    // convert to char
    char c = '\0';
    if (literal[0] == '\'' && literal [2] == '\'') {
        if (isprint(literal[1])) {
            c = static_cast<char>(literal[1]);
        std::cout << "char: '" << c << "'" << std::endl;
        }
        else
            std::cout << "char: Non displayable" << std::endl;
            //comment
    }
    else {
        char c = '\0';
        if (isprint(literal[0])) {
            c = static_cast<char>(literal[0]);
            std::cout << "char: '" << c << "'" << std::endl;
        }
        else
            std::cout << "char: Non displayable" << std::endl;
    }

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
    
    std::cout << "int identified" << std::endl;

    int num = 0;
    std::stringstream ss(literal);
    ss >> num;
    //std::cout << "int: " << num << std::endl;

    // char
    if (isprint(static_cast<char>(num)) != 0) {
        char c = static_cast<char>(num);
        std::cout << "char: '" << c << "'" << std::endl;
    }
    else if (isprint(static_cast<char>(num)) == 0)
        std::cout << "char: Non displayable" << std::endl;
    
    // int
    std::cout << "int: " << num << std::endl;

    // float
    float f = static_cast<float>(num);
    std::cout << "float: "
              << std::fixed << std::setprecision(1)
              << f << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);

    // double
    double d = static_cast<double>(num);
    std::cout << "double: "
              << std::fixed << std::setprecision(1)
              << d << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

bool ScalarConverter::IsFloatLiteral(std::string &literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        return true;
    }
    if (literal.find('f') != std::string::npos && literal.find('.') != std::string::npos) {
        int sign = 0;
        if (literal[0] == '-')
            sign = 1;
        if (literal[literal.length() - 1] != 'f')
            return false;
        for (size_t i = sign; i < literal.length() - 1; i++) {
            if (!isdigit(literal[i]) && literal[i] != '.')
                return false;
        }
        return true;
    }
    return false;
}

void ScalarConverter::ConvertFloatLiteral(std::string &literal) {    
    
    std::cout << "float identified" << std::endl;

    bool is_pseudo = false;

    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        is_pseudo = true;
    }
    float f = strtof(literal.c_str(), NULL);

    // char
    if (isprint(static_cast<char>(f)) != 0 || !is_pseudo) {
        char c = static_cast<char>(f);
        std::cout << "char: '" << c << "'" << std::endl;
    }
    else if (isprint(static_cast<char>(f)) == 0 && !is_pseudo)
        std::cout << "char: Non displayable" << std::endl;
    
    // int
    if (!is_pseudo) {
        int i = static_cast<int>(f);
        std::cout << "int: " << i << std::endl;
    }
    // float
    std::cout << "float: "
              << std::fixed << std::setprecision(1)
              << f << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);

    // double
    double d = static_cast<double>(f);
    std::cout << "double: "
              << std::fixed << std::setprecision(1)
              << d << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

bool ScalarConverter::IsDoubleLiteral(std::string &literal) {

    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        return true;
    }
    if (literal.find('f') == std::string::npos && literal.find('.') != std::string::npos) {
        int sign = 0;
        if (literal[0] == '-')
            sign = 1;
        if (literal[literal.length() - 1] == 'f')
            return false;
        for (size_t i = sign; i < literal.length(); i++) {
            if (!isdigit(literal[i]) && literal[i] != '.')
                return false;
        }
        return true;
    }
    return false;
}

void ScalarConverter::ConvertDoubleLiteral(std::string &literal) {    
    
    std::cout << "double identified" << std::endl;

    bool is_pseudo = false;

    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        is_pseudo = true;
    }
    double d = strtod(literal.c_str(), NULL);

    // char
    if (isprint(static_cast<char>(d)) != 0 || !is_pseudo)  {
        char c = static_cast<char>(d);
        std::cout << "char: '" << c << "'" << std::endl;
    }
    else if (isprint(static_cast<char>(d)) == 0 && !is_pseudo) 
        std::cout << "char: Non displayable" << std::endl;
    
    // int
    if (!is_pseudo) {
    int i = static_cast<int>(d);
    std::cout << "int: " << i << std::endl;
    }

    // float
    float f = static_cast<float>(d);
    std::cout << "float: "
              << std::fixed << std::setprecision(1)
              << f << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);

    // double
    std::cout << "double: "
              << std::fixed << std::setprecision(1)
              << d << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

// accept a string representation of a scalar literal and
// print its corresponding values interpreted as char, int, float or double
void ScalarConverter::convert(std::string &literal) {
     
    if (IsCharLiteral(literal) == true) { // char
        ConvertCharLiteral(literal);
    }
    else if (IsIntLiteral(literal) == true) { // int
        ConvertIntLiteral(literal);
    }
    else if (IsFloatLiteral(literal) == true) { // float
        ConvertFloatLiteral(literal);
    }
    else if (IsDoubleLiteral(literal) == true) { // double
        ConvertDoubleLiteral(literal);
    }
    else {
        std::cout << "Error: input is not a valid scalar literal. Conversion impossible." << std::endl;
    }
}