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

    std::set<int>  check_duplicates;
    for (int i = 1; i < ac; i++) {
        int sign = 0;
        if (av[i][0] == '-')
            throw std::invalid_argument("Error: negative value not allowed");
        if (av[i][0] == '+')
            sign = 1;
        std::string arg(av[i]);
        for (size_t j = sign; j < arg.size(); j++) {
            if (!isdigit(arg[j]))
                throw std::invalid_argument("Error: invalid argument1");
        }

        std::istringstream iss(arg);
        int num;
        iss >> num;

        if (!check_duplicates.empty() && check_duplicates.find(num) != check_duplicates.end())
            throw std::invalid_argument("Error: invalid argument2");
        check_duplicates.insert(num);

        numbers_vec.push_back(num);
        numbers_list.push_back(num);
    }
}

void PmergeMe::sort(void) {

    if (numbers_vec.size() < 2) {
        throw std::invalid_argument("Error: container too small to sort");
    }
    std::clock_t start = std::clock();

    std::cout << "Before:  ";
    printVec(numbers_vec);
    numbers_vec = mergeInsertion(numbers_vec);
    std::cout << "After:   ";
    printVec(numbers_vec);

    //std::cout << "Number of movements to sort: " << movement_count << std::endl;

    std::clock_t end = std::clock();
    
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << numbers_vec.size()
    << " elements with std::vector : " << std::fixed << std::setprecision(7) << duration
    << " seconds" << std::endl;
}

std::vector<int> PmergeMe::mergeInsertion(std::vector<int> vec) {

    std::vector<int>main;
    std::vector<int>other;
    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.end();

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

    if (vec.size() <= 1) {
        return vec;
    }
 
    main = mergeInsertion(main);

    // binary insertion is the binary search in the main container
    // to find where to insert the number from other container 
    // we'll be using either jacobsthal algorithm or another kind
    std::vector<int> jacob_insertion_order = getInsertionOrder(other.size());
    int counter = 0;
    for (size_t i = 0; i < jacob_insertion_order.size(); i++) {
        int low = 0;
        int high = main.size() - 1;
        int index = jacob_insertion_order[i];
        int value_to_find = other[index]; // iterating through every value of other
        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (main[middle] == value_to_find) {
                main.insert(main.begin() + middle, value_to_find);
                counter++;
                break;
            }

            if (main[middle] < value_to_find) {
                low = middle + 1;
            }
            else if (main[middle] > value_to_find) {
                high = middle - 1;
            }
            counter++;
        }
        main.insert(main.begin() + low, value_to_find);
    }
    movement_count = counter;
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
    int element = 1;
    jacobsthal.push_back(element);
    jacobsthal.push_back(element);
    while (element < (int)size) {
        element = element + (jacobsthal[index] * 2);
        jacobsthal.push_back(element);
        index++;
    }
    jacobsthal.erase(jacobsthal.begin());
    jacobsthal.pop_back();
    return jacobsthal;
}

// function to get sequence to insert, based on the size of the container and on the sequence
// of jacobsthal. It converts this previous sequence into a valid sequence
// returns this new sequence based on the jacobsthal sequence
// 0, 2, 4, 1, 3, ...
std::vector<int> PmergeMe::getInsertionOrder(size_t size) {

    std::vector<int> sequence;
    std::vector<bool> tracker(size, false); // tracker vector to check if index is already in sequence
    std::vector<int> jacobsthal = getJacobsthal(size);

    size_t index = 0;
    while (index < jacobsthal.size()) {
        int num = jacobsthal[index] - 1; // working with indexes, not values!
        sequence.push_back(num);
        tracker[num] = true;
        index++;
    }

    // iterate through numbers.vec
    // check if value in numbers.vec already is there, then skip. else place the new number there
    // use booleans
    for (size_t i = 0; i < size; i++) {
        if (tracker[i] == false) {
            sequence.push_back(i);
            tracker[i] = true;
        }
    }
    return sequence;
}