#include "RPN.hpp"

int main(int ac, char **av) {

    if (ac != 2) {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }

    try {
        RPN calculator = RPN();
        int result = calculator.process(av[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}