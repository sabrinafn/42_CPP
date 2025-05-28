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

/********************************************************************************/

char ScalarConverter::GetCharLiteral(std::string &literal) {

    if (literal.length() == 1 && !isdigit(literal[0]) && isprint(literal[0])) {
        if (isprint(literal[0])) {
            char c = static_cast<char>(literal[0]);
            std::cout << "char: '" << c << "'" << std::endl;
            return c;
        }
        else 
            std::cout << "char: Non displayable" << std::endl;
    }
    else if (literal.length() == 3 && literal[0] == '\''
            && literal[2] == '\'' && !isdigit(literal[1])) {
           if (isprint(literal[1])) {
               char c = static_cast<char>(literal[1]);
               std::cout << "char: '" << c << "'" << std::endl;
               return c;
           }    
        else 
        std::cout << "char: Non displayable" << std::endl;
    }
    return '\0';
}

void ScalarConverter::ConvertFromCharLiteral(char c) {    

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

int ScalarConverter::GetIntLiteral(std::string &literal, int &i) {
    if (literal.find('f') == std::string::npos && literal.find('.') == std::string::npos) {
        int sign = 0;
        if (literal[0] == '-')
            sign = 1;
        for (size_t j = sign; j < literal.length(); j++) {
            if (!isdigit(literal[j]))
                return false;
        }
        std::stringstream ss(literal);
        ss >> i;
        return true;
    }
    return false;
}

void ScalarConverter::ConvertFromIntLiteral(int i) {

    // char
    if (isprint(static_cast<char>(i)) != 0) {
        char c = static_cast<char>(i);
        std::cout << "char: '" << c << "'" << std::endl;
    }
    else if (isprint(static_cast<char>(i)) == 0)
        std::cout << "char: Non displayable" << std::endl;
    
    // int
    std::cout << "int: " << i << std::endl;

    // float
    float f = static_cast<float>(i);
    std::cout << "float: "
              << std::fixed << std::setprecision(1)
              << f << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);

    // double
    double d = static_cast<double>(i);
    std::cout << "double: "
              << std::fixed << std::setprecision(1)
              << d << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

float ScalarConverter::GetFloatLiteral(std::string &literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        return strtof(literal.c_str(), NULL);
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
        return strtof(literal.c_str(), NULL);
    }
    return false;
}

void ScalarConverter::ConvertFromFloatLiteral(float f) {

    if (std::isnan(f) || std::isinf(f)) {
        // char
        std::cout << "char: impossible" << std::endl;
        // int
        std::cout << "int: impossible" << std::endl;
    }
    else {
        // char
        if (isprint(static_cast<char>(f)) != 0) {
            char c = static_cast<char>(f);
            std::cout << "char: '" << c << "'" << std::endl;
        }
        else
            std::cout << "char: Non displayable" << std::endl;

        // int
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

double ScalarConverter::GetDoubleLiteral(std::string &literal) {

    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        return strtod(literal.c_str(), NULL);
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
        return strtod(literal.c_str(), NULL);
    }
    return false;
}

void ScalarConverter::ConvertFromDoubleLiteral(double d) {    

     if (std::isnan(((d))) || std::isinf(((d)))) {
        // char
        std::cout << "char: impossible" << std::endl;
        // int
        std::cout << "int: impossible" << std::endl;
    }
    else {
        // char
        if (isprint(static_cast<char>(((d)))) != 0) {
            char c = static_cast<char>(((d)));
            std::cout << "char: '" << c << "'" << std::endl;
        }
        else
            std::cout << "char: Non displayable" << std::endl;

        // int
        int i = static_cast<int>(((d)));
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
     
    int i = 0;
    if (char c = GetCharLiteral(literal)) { // char
        ConvertFromCharLiteral(c);
    }
    else if (GetIntLiteral(literal, i)) { // int
        ConvertFromIntLiteral(i);
    }
    else if (float f = GetFloatLiteral(literal)) { // float
        ConvertFromFloatLiteral(f);
    }
    else if (double d = GetDoubleLiteral(literal)) { // double
        ConvertFromDoubleLiteral(d);
    }
    else {
        std::cout << "Error: input is not a valid scalar literal. Conversion impossible." << std::endl;
    }
}