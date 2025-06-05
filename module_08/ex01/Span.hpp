#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
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

        void addNumber(int N); // add number to Span
        //void addRange();
        void shortestSpan(void); // shortest distance between all numbers
        void longestSpan(void); // longest distance between all numbers
};

#endif