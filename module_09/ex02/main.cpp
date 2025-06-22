#include "PmergeMe.hpp"

int main(int ac, char **av) {
    
    if (ac == 1) {
        std::cerr << "Error: missing argument" << std::endl;
        return 1;
    }

    try {
        PmergeMe unsorted = PmergeMe();
        unsorted.parseInput(ac, av);
        unsorted.printBefore();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}