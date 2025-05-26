#include "ScalarConverter.hpp"

int main(void) {

    std::string achar = "a";
    std::string aint = "-42";
    std::string afloat = "3.14f";
    std::string adouble = "3.14";

    ScalarConverter::convert(achar);
    ScalarConverter::convert(aint);
}