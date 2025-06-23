#include "PmergeMe.hpp"

/* CONSTRUCTORS */
PmergeMe::PmergeMe(void) : numbers_vec(), numbers_list() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other;}

/* DESTRUCTORS */
PmergeMe::~PmergeMe(void) {}

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

void PmergeMe::sort(void) {

    std::cout << "Merge insertion:" << std::endl;

    std::vector<int> result = mergeInsertion(numbers_vec);
    std::cout << "\nResult from mergeInsertion function: ";
    printVec(result);

}

std::vector<int> PmergeMe::mergeInsertion(std::vector<int> vec) {

    std::vector<int>main;
    std::vector<int>other;

    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.end();
    
    while (start < end - 1) {
        if (*start < *(start + 1)) {
            other.push_back(*start);
            main.push_back(*(start + 1));
        }
        else {
            other.push_back(*(start + 1));
            main.push_back(*start);
        }
        start += 2;
    }
    if (vec.size() % 2 != 0 && start != end)
        other.push_back(*start);

    std::cout << "bigger numbers: ";
    printVec(main);
    std::cout << "smaller numbers: ";
    printVec(other);

    if (main.size() == 1) {
        return main;
    }

    main = mergeInsertion(main);

    return main;
}

void PmergeMe::printVec(std::vector<int> vec) {

    std::vector<int>::iterator it = vec.begin();
    while (it < vec.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}