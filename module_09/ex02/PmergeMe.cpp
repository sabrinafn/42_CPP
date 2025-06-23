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

void PmergeMe::sort(void) {

    std::cout << "=== Merge insertion ===" << std::endl;

    printVec(getJacobsthal(10));

    std::cout << "Before: ";
    printVec(numbers_vec);
    numbers_vec = mergeInsertion(numbers_vec);
    std::cout << "\nAfter:  ";
    printVec(numbers_vec);

}

std::vector<int> PmergeMe::mergeInsertion(std::vector<int> vec) {

    std::vector<int>main;
    std::vector<int>other;

    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.end();
    std::cout << "\n";
    std::cout << "container received as parameter: ";
    printVec(vec);
    std::cout << "\n";

    while (start + 1 < end) {
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
    if (start != end)
        other.push_back(*start);

    std::cout << "bigger numbers: ";
    printVec(main);
    std::cout << "smaller numbers: ";
    printVec(other);

    if (vec.size() <= 1) {
        return vec;
    }
 
    main = mergeInsertion(main);

    // binary insertion is the binary search in the main container
    // to find where to insert the number from other container 
    // we'll be using either jacobsthal algorithm or another kind

    int counter = 0;
    for (size_t i = 0; i < other.size(); i++) {
        int low = 0;
        int high = main.size() - 1;
        int value_to_find = other[i]; // iterating through every value of other
        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (main[middle] == value_to_find) {
                std::cout << "main[middle] == value_to_find" << std::endl;
                std::cout << main[middle] << "==" << value_to_find << std::endl;
                main.insert(main.begin() + middle, value_to_find);
                counter++;
                break;
            }

            if (main[middle] < value_to_find) {
                low = middle + 1;
                std::cout << "main[middle] < value_to_find" << std::endl;
                std::cout << main[middle] << "<" << value_to_find << std::endl;
            }
            else if (main[middle] > value_to_find) {
                high = middle - 1;
                std::cout << "main[middle] > value_to_find" << std::endl;
                std::cout << main[middle] << ">" << value_to_find << std::endl;
            }
            counter++;
        }
        main.insert(main.begin() + low, value_to_find);
        std::cout << "bigger numbers: ";
        printVec(main);
        std::cout << "smaller numbers: ";
        printVec(other);
    }
    std::cout << "counter = " << counter << std::endl;
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

// function to generate jacobsthal sequence, based on the size of the container
// and return its sequence
// 1, 1, 3, 5, 11, 21, 43, 85, ...
std::vector<int> PmergeMe::getJacobsthal(size_t size) {

    std::vector<int> jacobsthal;
    size_t index = 0;
    int element = 0;
    jacobsthal.push_back(element);
    element++;
    jacobsthal.push_back(element);
    while (index < size) {
        element = element + (jacobsthal[index] * 2);
        jacobsthal.push_back(element);
        index++;
    }
    printVec(jacobsthal);
    return jacobsthal;
}

// function to get sequence to insert, based on the size of the container and on the sequence
// of jacobsthal. It converts this previous sequence into a valid sequence
// returns this new sequence based on the jacobsthal sequence
// 0, 2, 4, 1, 3, ...

// use this last sequence in the for loop of mergeInsertion function