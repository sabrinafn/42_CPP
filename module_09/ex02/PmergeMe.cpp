#include "PmergeMe.hpp"

/* CONSTRUCTORS */
PmergeMe::PmergeMe() : numbers() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other;}

/* DESTRUCTORS */
PmergeMe::~PmergeMe() {}

/* OPERATORS */
PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        (void)other;
    }
    return *this;
}

void PmergeMe::parseInput(int ac, char **av) {

    for (int i = 1; i < ac; i++) {
        int sign = 0;
        if (av[i][0] == '-')
            throw std::invalid_argument("Error: negative value not allowed");
        if (av[i][0] == '+')
            sign = 1;
        std::string arg(av[i]);
        for (size_t j = sign; j < arg.size(); j++) {
            if (!isdigit(arg[j]))
                throw std::invalid_argument("Error: invalid argument");
        }
        std::istringstream iss(arg);
        long num;
        iss >> num;

        numbers.push_back(static_cast<int>(num));
    }
}

void PmergeMe::printBefore(void) {

    std::vector<int>::iterator it = numbers.begin();
    std::cout << "Before: "; 
    while (it < numbers.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}