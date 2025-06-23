#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm> // std::is_sorted()

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
        void sort(void);
        std::vector<int> mergeInsertion(std::vector<int> vec);
        void printVec(std::vector<int> vec);

};

//std::is_sorted()

#endif