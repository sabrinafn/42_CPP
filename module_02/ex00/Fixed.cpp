#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0) {

    std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed &other)
    : fixed_point_value(other.fixed_point_value) {

    std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment Operator Overload
Fixed&  Fixed::operator=(const Fixed &other) {

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // check if it is not assigning to itself
      fixed_point_value = other.fixed_point_value;
    return *this; // Return a reference to the current object
}

Fixed::~Fixed() {

    std::cout << "Default destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const {

    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point_value;
}

void    Fixed::setRawBits(int const raw) {

    fixed_point_value = raw;

}