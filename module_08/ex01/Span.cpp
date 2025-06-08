#include "Span.hpp"

    //unsigned int max_size;
    //std::vector<int> vec;

    /* CONSTRUCTORS */

// constructor
Span::Span(void) : max_size(0) {}

// constructor unsigned int
Span::Span(unsigned int N) : max_size(N) {} 

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

void Span::addNumber(int value) {

    if (this->vec.size() >= this->max_size)
        throw std::range_error("Cannot add number - Container is at maximum limit.");
    this->vec.push_back(value);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {

    std::vector<int>::iterator it;
    for (it = begin; it != end; it++) {
        addNumber(*it);
    }
}

// shortest distance between all numbers
int Span::shortestSpan(void) {

    if (this->vec.size() <= 1)
        throw std::range_error("Span can't be found - Not enough elements.");
    
    std::vector<int>::iterator it;

    int span_found = std::abs(this->vec[1] - this->vec[0]);

    for (it = this->vec.begin(); it + 1 != vec.end(); it++) {
        int temp = std::abs(*(it + 1) - *it);
        if (span_found > temp)
            span_found = temp;
    }
    return span_found;
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

void Span::printVec(void) {

    std::vector<int>::iterator it;
    std::cout << "Values stored in container: { ";
    for (it = this->vec.begin(); it != this->vec.end(); it++) {
        std::cout << *it;
        if (it != this->vec.end() - 1)
            std::cout << ", ";
    }
    std::cout << " }" << std::endl;
}

// // insertion operator
// std::ostream &operator<<(std::ostream &out, const Span &other) {

//     std::vector<int>::iterator it;

//     for (it = &other.vec.begin(); it != other.end())
//     out << ;
//     return out;
// }
