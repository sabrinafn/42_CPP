#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <set>

class PmergeMe {

    private:
        std::vector<int>    numbers_vec;
        std::list<int>      numbers_list;
        int                 movement_count;
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