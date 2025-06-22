#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

class PmergeMe {

    private:
        std::vector<int> numbers_vec;
        std::list<int> numbers_list;
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