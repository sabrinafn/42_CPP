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


// insertion operator
std::ostream& operator<<(std::ostream& os, const Span& span) {

    std::vector<int> temp_vec = span.getVec();
    std::vector<int>::iterator it;

    os << "Span (" << temp_vec.size() << "/" << span.getMaxSize() << "): { ";
    for (it = temp_vec.begin(); it != temp_vec.end(); it++) {
        os << *it;
        if (it != temp_vec.end() - 1)
            os << ", ";
    }
    os << " }";
    return os;
}

    /* GETTERS */

std::vector<int> Span::getVec(void) const {
    return this->vec;
}

unsigned int     Span::getMaxSize(void) const {
    return this->max_size;
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

std::vector<int>  generateRandomDigits(int size) {

    std::vector<int> vec;
    static bool rand_exist = false;

    // seed the random generator
    if (!rand_exist) {
        std::srand(std::time(0));
        rand_exist = true;
    }

    for (int i = 0; i < size; i++) {
        int random = std::rand() % 10;
        vec.push_back(random);
    }
    return vec;
}

// shortest distance between all numbers
int Span::shortestSpan(void) {

    if (this->vec.size() <= 1)
        throw std::range_error("Span can't be found - Not enough elements.");
    

    std::vector<int> temp_vec = this->getVec();
    std::sort(temp_vec.begin(), temp_vec.end());
    std::vector<int>::iterator it;

    int span_found = std::abs(temp_vec[1] - temp_vec[0]);

    for (it = temp_vec.begin(); it + 1 != temp_vec.end(); it++) {
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

    int min_it = *std::min_element(this->vec.begin(), this->vec.end());
    int max_it = *std::max_element(this->vec.begin(), this->vec.end());
    
    int span_found = max_it - min_it;

    return span_found;
}
