#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "iostream"

class Span {

    private:
        unsigned int max_size;
        std::vector<int> vec;

    public:
        /* CONSTRUCTORS */
        Span(void); // constructor
        Span(unsigned int N); // constructor unsigned int
        Span(const Span& other); // copy constructor

        /* DESTRUCTOR */
        ~Span(void);

        /* OPERATORS */
        Span& operator=(const Span& other); // copy assignment operator

        /* METHODS */

        // Add numbers to vec
        void addNumber(int value);
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        // get shortest/longest span(distance) between all numbers
        int shortestSpan(void);
        int longestSpan(void);

        // getters
        std::vector<int> getVec(void) const;
        unsigned int     getMaxSize(void) const;
};

std::ostream &operator<<(std::ostream &out, const Span &other); // insertion operator
std::vector<int>   generateRandomDigits(int size);

#endif