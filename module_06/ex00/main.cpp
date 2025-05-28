#include "ScalarConverter.hpp"

int main(int ac, char **av) {

    if (ac == 2) {
        std::string str = av[1];
        ScalarConverter::convert(str);
    }
    else {
        std::cout << "Usage: ./ScalarConverter <literal>\n";
        std::cout << "Provide a single C++ scalar literal (as a string) to convert.\n";
        std::cout << "Examples:\n";
        std::cout << "  ./ScalarConverter 'a'    => char literal\n";
        std::cout << "  ./ScalarConverter 42       => int literal\n";
        std::cout << "  ./ScalarConverter 42.0f    => float literal\n";
        std::cout << "  ./ScalarConverter 42.0     => double literal\n";
    }
    return 0;    
}