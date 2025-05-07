#include "IMateriaSource.hpp"

// constructor
IMateriaSource::IMateriaSource() {
    std::cout << "IMateriaSource: Constructor called" << std::endl;
}

// copy constructor
IMateriaSource::IMateriaSource(const IMateriaSource &other) {
    std::cout << "IMateriaSource: Copy Constructor called" << std::endl;
    *this = other;
}

// copy assignment operator
IMateriaSource& IMateriaSource::operator=(const IMateriaSource &other) {
    std::cout << "IMateriaSource: Copy Assignment operator called" << std::endl;
    if (this != &other) {
        *this = other;
    }
    return *this;
}