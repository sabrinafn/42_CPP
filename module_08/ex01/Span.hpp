#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
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

        // Add numbers to vec
        void addNumber(int value);
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        // get shortest/longest span(distance) between all numbers
        int shortestSpan(void);
        int longestSpan(void);

        // getter for vec
        void printVec(void);
};

//std::ostream &operator<<(std::ostream &out, const Span &other); // insertion operator

#endif