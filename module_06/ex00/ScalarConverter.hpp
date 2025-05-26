#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class ScalarConverter {
    
    private:
        ScalarConverter(void); // constructor
        ScalarConverter(const ScalarConverter &other); // copy constructor
        ScalarConverter& operator=(const ScalarConverter &other); // copy assignment operator
        ~ScalarConverter(void); // destructor

        static bool IsCharLiteral(std::string &literal);
        static bool IsIntLiteral(std::string &literal);
        static bool IsFloatLiteral(std::string &literal);
        static bool IsDoubleLiteral(std::string &literal);

        static void ConvertCharLiteral(std::string &literal);
        static void ConvertIntLiteral(std::string &literal);
        static void ConvertFloatLiteral(std::string &literal);
        static void ConvertDoubleLiteral(std::string &literal);

    public:
        // accept a string representation of a scalar literal and
        // print its corresponding values interpreted as char, int, float or double
        static void convert(std::string &literal);
};

#endif