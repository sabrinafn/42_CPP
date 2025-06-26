#include "PmergeMe.hpp"

/* CONSTRUCTORS */
PmergeMe::PmergeMe(void) : numbers_vec(), numbers_deq(), movement_count_vec(0), movement_count_deq(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other;}

/* DESTRUCTORS */
PmergeMe::~PmergeMe(void) {}

/* OPERATORS */
PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->numbers_vec = other.numbers_vec;
        this->numbers_deq = other.numbers_deq;
    }
    return *this;
}

void PmergeMe::parseInput(int ac, char **av) {

    std::set<int>  check_duplicates;
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-')
            throw std::invalid_argument("Error: negative value not allowed");
        if (av[i][0] == '+')
            throw std::invalid_argument("Error: unsigned values only");
        std::string arg(av[i]);
        for (size_t j = 0; j < arg.size(); j++) {
            if (!isdigit(arg[j]))
                throw std::invalid_argument("Error: value is not a digit");
        }

        std::istringstream iss(arg);
        int num;
        iss >> num;

        if (check_duplicates.find(num) != check_duplicates.end())
            throw std::invalid_argument("Error: duplicate values not allowed");
        check_duplicates.insert(num);

        numbers_vec.push_back(num);
        numbers_deq.push_back(num);
    }
}

void PmergeMe::sort(void) {

    std::clock_t start_deque = std::clock();
    sortDeque();
    std::clock_t end_deque = std::clock();
    
    std::cout << "Before              :  ";
    printContainer(numbers_vec);
    std::clock_t start_vector = std::clock();
    sortVector();
    std::clock_t end_vector = std::clock();
    std::cout << "After (std::vector) :  ";
    printContainer(numbers_vec);
    std::cout << "After (std::deque)  :  ";
    printContainer(numbers_deq);

    std::cout << "Movement count with std::vector : " << movement_count_vec << std::endl;
    std::cout << "Movement count with std::deque  : " << movement_count_deq << std::endl;

    
    double duration = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << numbers_vec.size()
    << " elements with std::vector : " << std::fixed << std::setprecision(7) << duration
    << " seconds" << std::endl;

    duration = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << numbers_deq.size()
    << " elements with std::deque  : " << std::fixed << std::setprecision(7) << duration
    << " seconds" << std::endl;
}

void PmergeMe::sortVector(void) {
    if (numbers_vec.size() == 1) {
        std::cout << "return size == 1" << std::endl;
        return;
    }
    numbers_vec = mergeInsertionVec(numbers_vec);
}

std::vector<int> PmergeMe::mergeInsertionVec(std::vector<int> vec) {

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
 
    main = mergeInsertionVec(main);

    // binary insertion is the binary search in the main container
    // to find where to insert the number from other container 
    // we'll be using either jacobsthal algorithm or another kind
    std::vector<int> jacob_insertion_order = getInsertionOrderVec(other.size());
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
    movement_count_vec = counter;
    return main;
}


// function to get sequence to insert, based on the size of the container and on the sequence
// of jacobsthal. It converts this previous sequence into a valid sequence
// returns this new sequence based on the jacobsthal sequence
// 0, 2, 4, 1, 3, ...
std::vector<int> PmergeMe::getInsertionOrderVec(size_t size) {

    std::vector<int> sequence;
    std::vector<bool> tracker(size, false); // tracker vector to check if index is already in sequence
    std::vector<int> jacobsthal = getJacobsthal<std::vector<int> >(size);

    size_t index = 0;
    while (index < jacobsthal.size()) {
        int num = jacobsthal[index] - 1;
        sequence.push_back(num);
        tracker[num] = true;
        index++;
    }

    // iterate through container
    // check if value is not already there with boolean tracker   
    // then place the new value there
    for (size_t i = 0; i < size; i++) {
        if (tracker[i] == false) {
            sequence.push_back(i);
            tracker[i] = true;
        }
    }
    return sequence;
}


/************************************************************************/


void PmergeMe::sortDeque(void) {
    if (numbers_deq.size() == 1)
        return;
    numbers_deq = mergeInsertionDeq(numbers_deq);
}

std::deque<int> PmergeMe::mergeInsertionDeq(std::deque<int> deq) {

    std::deque<int>main;
    std::deque<int>other;
    std::deque<int>::iterator start = deq.begin();
    std::deque<int>::iterator end = deq.end();

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

    if (deq.size() <= 1) {
        return deq;
    }
 
    main = mergeInsertionDeq(main);

    // binary insertion is the binary search in the main container
    // to find where to insert the number from other container 
    // we'll be using either jacobsthal algorithm or another kind
    std::deque<int> jacob_insertion_order = getInsertionOrderDeq(other.size());
    int counter = 0;
    for (size_t i = 0; i < jacob_insertion_order.size(); i++) {
        int low = 0;
        int high = main.size() - 1;
        int current_index = jacob_insertion_order[i];
        int value_to_insert = other[current_index];
        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (main[middle] == value_to_insert) {
                main.insert(main.begin() + middle, value_to_insert);
                counter++;
                break;
            }

            if (main[middle] < value_to_insert) {
                low = middle + 1;
            }
            else if (main[middle] > value_to_insert) {
                high = middle - 1;
            }
            counter++;
        }
        main.insert(main.begin() + low, value_to_insert);
    }
    movement_count_deq = counter;
    return main;
}

// function to get sequence to insert, based on the size of the container and on the sequence
// of jacobsthal. It converts this previous sequence into a valid sequence
// returns this new sequence based on the jacobsthal sequence
// 0, 2, 4, 1, 3, ...
std::deque<int> PmergeMe::getInsertionOrderDeq(size_t size) {

    std::deque<int> sequence;
    std::deque<bool> tracker(size, false); // tracker deque to check if index is already in sequence
    std::deque<int> jacobsthal = getJacobsthal<std::deque<int> >(size);

    size_t index = 0;
    while (index < jacobsthal.size()) {
        int num = jacobsthal[index] - 1;
        sequence.push_back(num);
        tracker[num] = true;
        index++;
    }

    // iterate through container
    // check if value is not already there with boolean tracker   
    // then place the new value there
    for (size_t i = 0; i < size; i++) {
        if (tracker[i] == false) {
            sequence.push_back(i);
            tracker[i] = true;
        }
    }
    return sequence;
}
