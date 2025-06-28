#include "PmergeMe.hpp"
#include <iomanip>

int main(int ac, char **av) {
    try {
        PmergeMe unsorted = PmergeMe();
        unsorted.parseInput(ac, av);
        unsorted.sort();

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}