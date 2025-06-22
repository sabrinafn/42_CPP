#include "PmergeMe.hpp"

int main(int ac, char **av) {
    
    if (ac == 1) {
        std::cerr << "Error: missing argument" << std::endl;
        return 1;
    }

    for (int i = 1; i < ac; i++) {
        int sign = 0;
        if (av[i][0] == '-') {
            std::cerr << "Error: negative value not allowed" << std::endl;
            return 1;
        }
        if (av[i][0] == '+')
            sign = 1;
        std::string arg(av[i]);
        for (size_t j = sign; j < arg.size(); j++) {
            if (!isdigit(arg[j])) {
                std::cerr << "Error: invalid argument" << std::endl;
                return 1;
            }
        }
    }
    return 0;
}