#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>

class PmergeMe {

    private:
        std::vector<int> numbers;
    public:
        /* CONSTRUCTORS */
        PmergeMe(void);
        PmergeMe(const PmergeMe &other);

        /* DESTRUCTORS */
        ~PmergeMe(void);

        /* OPERATORS */
        PmergeMe& operator=(const PmergeMe &other);

        void parseInput(int ac, char **av);
        void printBefore(void);

};

#endif