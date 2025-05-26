#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>

class ScalarConverter {
    
    private:
        ScalarConverter(void); // constructor
        ScalarConverter(const ScalarConverter &other); // copy constructor
        ScalarConverter& operator=(const ScalarConverter &other); // copy assignment operator
        ~ScalarConverter(void); // destructor

    public:
        // accept a string representation of a scalar literal and
        // print its corresponding values interpreted as char, int, float or double
        static void convert(std::string &literal);

        static bool ConvertToChar(std::string &literal);
        static bool ConvertToInt(std::string &literal);
};

#endif