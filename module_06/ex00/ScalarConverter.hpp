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

        // IDENTIFY AND RETURN TYPE
        static char GetCharLiteral(const std::string &literal);
        static bool GetIntLiteral(const std::string &literal, int &i);
        static bool GetFloatLiteral(const std::string &literal, float &f);
        static bool GetDoubleLiteral(const std::string &literal, double &d);

        // CONVERSION FUNCTIONS
        static void ConvertFromCharLiteral(char c);
        static void ConvertFromIntLiteral(int i);
        static void ConvertFromFloatLiteral(float f);
        static void ConvertFromDoubleLiteral(double d);
        static void ConvertFloatAndDouble(double d);

        // HELPER FUNCTIONS
        static bool FindCharOneOccurrence(const std::string& literal, char c);
        static void PrintChar(char c);
        static void PrintInt(int i);
        static void PrintFloat(float f);
        static void PrintDouble(double d);

    public:
        // accept a string representation of a scalar literal and
        // print its corresponding values interpreted as char, int, float or double
        static void convert(std::string &literal);

    
};

#endif