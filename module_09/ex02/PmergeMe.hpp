#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector> // container
#include <list> // container
#include <set> // container
#include <ctime>
#include <iomanip>


class PmergeMe {

    private:
        std::vector<int>    numbers_vec;
        std::list<int>      numbers_list;
        int                 movement_count;
        unsigned int        start_time;

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
        void sort(void);
        std::vector<int> mergeInsertion(std::vector<int> vec);
        void printVec(std::vector<int> vec);
        std::vector<int> getJacobsthal(size_t size);
        std::vector<int> getInsertionOrder(size_t size);
};

#endif