#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
    
    private:
        ScalarConverter(); // constructor
        ScalarConverter(const ScalarConverter &other); // copy constructor
        ScalarConverter& operator=(const ScalarConverter &other); // copy assignment operator
        ~ScalarConverter(); // destructor

    public:
        // accept a string representation of a scalar literal and
        // print its corresponding values interpreted as char, int, float or double
        static void convert(std::string &literal);
};

#endif