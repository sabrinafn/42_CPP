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
// IDENTIFY AND RETURN TYPE

char ScalarConverter::GetCharLiteral(const std::string &literal) {

    if (literal.length() == 1 && !isdigit(literal[0])) {
        if (isprint(literal[0])) {
            char c = static_cast<char>(literal[0]);
            PrintChar(c);
            return c;
        }
        else 
            std::cout << "char: Non displayable" << std::endl;
    }
    else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
           if (isprint(literal[1])) {
               char c = static_cast<char>(literal[1]);
               PrintChar(c);
               return c;
           }    
        else 
        std::cout << "char: Non displayable" << std::endl;
    }
    return '\0';
}

bool ScalarConverter::GetIntLiteral(const std::string &literal, int &i) {

    if (literal.find('f') == std::string::npos && literal.find('.') == std::string::npos) {
        int sign = 0;
        if (literal[0] == '-' || literal[0] == '+')
            sign = 1;
        for (size_t j = sign; j < literal.length(); j++) {
            if (!isdigit(literal[j]))
                return false;
        }
        std::stringstream txt_file(literal); // stringstream acts likea file
        txt_file >> i;
        return true;
    }
    return false;
}

bool ScalarConverter::GetFloatLiteral(const std::string &literal, float &f) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        f = strtof(literal.c_str(), NULL);
        return true;
    }
    if (FindCharOneOccurrence(literal, '.') == true && literal.find('f') != std::string::npos) {
        int sign = 0;
        if (literal[0] == '-' || literal[0] == '+')
            sign = 1;
        for (size_t i = sign; i < literal.length() - 1; i++) {
            if (!isdigit(literal[i]) && literal[i] != '.')
                return false;
        }
        f = strtof(literal.c_str(), NULL);
        return true;
    }
    return false;
}

bool ScalarConverter::GetDoubleLiteral(const std::string &literal, double &d) {

    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        d = strtod(literal.c_str(), NULL);
        return true;
    }
    if (FindCharOneOccurrence(literal, '.') == true) {
        int sign = 0;
        if (literal[0] == '-' || literal[0] == '+')
            sign = 1;
        for (size_t i = sign; i < literal.length(); i++) {
            if (!isdigit(literal[i]) && literal[i] != '.')
                return false;
        }
        d = strtod(literal.c_str(), NULL);
        return true;
    }
    return false;
}

/********************************************************************************/
// CONVERSION FUNCTIONS

void ScalarConverter::ConvertFromCharLiteral(char c) {

    // int
    int i = static_cast<int>(c);
    PrintInt(i);

    // float
    float f = static_cast<float>(c);
    PrintFloat(f);

    // double
    double d = static_cast<double>(c);
    PrintDouble(d);
}

void ScalarConverter::ConvertFromIntLiteral(int i) {

    // if it's within ascii range
    if (i < 0 || i > 255) {
        std::cout << "char: impossible" << std::endl;
    }
    else if (isprint(static_cast<char>(i)) != 0) { // char
        char c = static_cast<char>(i);
        PrintChar(c);
    }
    else
        std::cout << "char: Non displayable" << std::endl;
    
    // int
    PrintInt(i);

    // float
    float f = static_cast<float>(i);
    PrintFloat(f);

    // double
    double d = static_cast<double>(i);
    PrintDouble(d);
}

void ScalarConverter::ConvertFromFloatLiteral(float f) {

    ConvertFloatAndDouble(static_cast<double>(f));
}

void ScalarConverter::ConvertFromDoubleLiteral(double d) {    

    ConvertFloatAndDouble(d);
}

void ScalarConverter::ConvertFloatAndDouble(double d) {

    if (std::isnan(d) || std::isinf(d)) {
        // char
        std::cout << "char: impossible" << std::endl;
        // int
        std::cout << "int: impossible" << std::endl;
    }
    else {
        // char
        if (static_cast<int>(d) < 0 || static_cast<int>(d) > 255) {
            std::cout << "char: impossible" << std::endl;
        }
        else if (isprint(static_cast<char>(d)) != 0) {
            char c = static_cast<char>(d);
            PrintChar(c);
        }
        else
            std::cout << "char: Non displayable" << std::endl;

        // int
        int i = static_cast<int>(d);
        PrintInt(i);    
    }

    // float
    float f = static_cast<float>(d);
    PrintFloat(f); 

    // double
    PrintDouble(d); 
}
/********************************************************************************/
// HELPER FUNCTIONS

bool ScalarConverter::FindCharOneOccurrence(const std::string& literal, char c) {
    
    int count = 0;
    for (size_t i = 0; i < literal.length(); i++) {
        if (literal[i] == c)
            ++count;
    }
    if (count == 1)
        return true;
    return false;
}

void    ScalarConverter::PrintChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
}

void    ScalarConverter::PrintInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void    ScalarConverter::PrintFloat(float f) {
    std::cout << "float: "
              << std::fixed << std::setprecision(2)
              << f << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

void    ScalarConverter::PrintDouble(double d) {
    std::cout << "double: "
              << std::fixed << std::setprecision(2)
              << d << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

/********************************************************************************/
// accept a string representation of a scalar literal and
// print its corresponding values interpreted as char, int, float or double

void ScalarConverter::convert(std::string &literal) {

    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    
    if (char c = GetCharLiteral(literal)) { // char
        ConvertFromCharLiteral(c);
        return ;
    }
    if (GetIntLiteral(literal, i)) { // int
        ConvertFromIntLiteral(i);
        return ;
    }
    if (GetFloatLiteral(literal, f)) { // float
        ConvertFromFloatLiteral(f);
        return ;
    }
    if (GetDoubleLiteral(literal, d)) { // double
        ConvertFromDoubleLiteral(d);
        return ;
    }
    std::cout << "Error: input is not a valid scalar literal. Conversion impossible." << std::endl;
}