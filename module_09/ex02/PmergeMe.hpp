#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector> // container
#include <deque> // container
#include <set> // container for error check only
#include <ctime>
#include <iomanip>


class PmergeMe {

    private:
        /* CONTAINERS */
        std::vector<int>    numbers_vec;
        std::deque<int>     numbers_deq;

        /* ATTRIBUTES */
        int                 movement_count_vec;
        int                 movement_count_deq;

        /* PRIVATE METHODS */

        void sortVector(void);
        std::vector<int> mergeInsertionVec(std::vector<int> vec);
        std::vector<int> getInsertionOrderVec(size_t size);

        void sortDeque(void);
        std::deque<int> mergeInsertionDeq(std::deque<int> deq);
        std::deque<int> getInsertionOrderDeq(size_t size);


        /* TEMPLATES */

        // method to print containers
        template <typename T_container>
        void printContainer(T_container& container) {
            typename T_container::iterator it = container.begin();
            while (it != container.end()) {
                std::cout << *it << " ";
                it++;
            }
            std::cout << std::endl;
        }

        // method to generate jacobsthal sequence based on the size of the container.
        // returns the sequence 1, 1, 3, 5, 11, 21, 43, 85, ... 
        template <typename T_container>
        T_container getJacobsthal(size_t size) {
            T_container jacobsthal;
            size_t index = 0;
            int element = 1;
            jacobsthal.push_back(element);
            jacobsthal.push_back(element);
            while (element <= (int)size) {
                element = element + (jacobsthal[index] * 2);
                jacobsthal.push_back(element);
                index++;
            }
            jacobsthal.erase(jacobsthal.begin());
            jacobsthal.pop_back();
            return jacobsthal;
        }

    public:
        /* CONSTRUCTORS */
        PmergeMe(void);
        PmergeMe(const PmergeMe &other);

        /* DESTRUCTORS */
        ~PmergeMe(void);

        /* OPERATORS */
        PmergeMe& operator=(const PmergeMe &other);

        /* PUBLIC METHODS */
        void parseInput(int ac, char **av);
        void sort(void);

};

#endif