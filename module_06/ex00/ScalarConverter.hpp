#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

class ScalarConverter {
    
    private:
        ScalarConverter(void); // constructor
        ScalarConverter(const ScalarConverter &other); // copy constructor
        ScalarConverter& operator=(const ScalarConverter &other); // copy assignment operator
        ~ScalarConverter(void); // destructor

        static char GetCharLiteral(std::string &literal);
        static bool GetIntLiteral(std::string &literal, int &i);
        static bool GetFloatLiteral(std::string &literal, float &f);
        static bool GetDoubleLiteral(std::string &literal, double &d);

        static void ConvertFromCharLiteral(char c);
        static void ConvertFromIntLiteral(int i);
        static void ConvertFromFloatLiteral(float f);
        static void ConvertFromDoubleLiteral(double d);

        static bool FindCharOneOccurrence(std::string& literal, char c);

    public:
        // accept a string representation of a scalar literal and
        // print its corresponding values interpreted as char, int, float or double
        static void convert(std::string &literal);

    
};

#endif