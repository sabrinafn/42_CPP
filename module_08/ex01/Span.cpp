#include "Span.hpp"

    //unsigned int max_size;
    //std::vector<int> vec;

    /* CONSTRUCTORS */

// constructor
Span::Span(void) : max_size(0), vec(max_size) {}

// constructor unsigned int
Span::Span(unsigned int N) : max_size(N), vec(N){} // wrong

// copy constructor
Span::Span(const Span& other) {
    *this = other;
}

    /* DESTRUCTOR */

Span::~Span(void) {}

    /* OPERATORS */

// copy assignment operator
Span& Span::operator=(const Span& other) {
    if (this != &other) { // check if not assigning object to itself
        this->max_size = other.max_size;
        this->vec = other.vec;
    }
    return *this;
}

    /* METHODS */

void Span::addNumber(int N) {

    if (this->vec.size() >= this->max_size)
        throw std::range_error("Container is at maximum limit.");
    this->vec.push_back(N);
}

//void Span::addRange() {}

// shortest distance between all numbers
int Span::shortestSpan(void) {

    if (this->vec.size() <= 1)
        throw std::range_error("Span can't be found - Not enough elements.");
    
    return 0;
}

// longest distance between all numbers
int Span::longestSpan(void) {

    if (this->vec.size() <= 1)
        throw std::range_error("Span can't be found - Not enough elements.");

    std::vector<int>::iterator min_it;
    std::vector<int>::iterator max_it;

    min_it = std::min_element(this->vec.begin(), this->vec.end());
    max_it = std::max_element(this->vec.begin(), this->vec.end());
    
    int span_found = max_it - min_it;

    return span_found;
}