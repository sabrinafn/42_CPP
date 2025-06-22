#include "PmergeMe.hpp"

/* CONSTRUCTORS */
PmergeMe::PmergeMe() : numbers_vec(), numbers_list() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other;}

/* DESTRUCTORS */
PmergeMe::~PmergeMe() {}

/* OPERATORS */
PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->numbers_vec = other.numbers_vec;
        this->numbers_list = other.numbers_list;
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

        numbers_vec.push_back(static_cast<int>(num));
        numbers_list.push_back(static_cast<int>(num));
    }
}

void PmergeMe::printBefore(void) {

    std::vector<int>::iterator it = numbers_vec.begin();
    std::cout << "Before: "; 
    while (it < numbers_vec.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}