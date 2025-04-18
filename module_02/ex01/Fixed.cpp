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

Fixed::Fixed(const int n) {

    // bitwise operator to move bits to the left
    // 5 = 00000101
    // n << fractional_bits = 0000010100000000
    n << fractional_bits;
}

Fixed::Fixed(const float f) {

    // Pense em frações decimais. 
    // Se você tem o número 3.14,
    // você pode pensar nele como 3 + 14/100.
    // O que estamos fazendo com o ponto fixo é 
    // semelhante, mas com potências de 2 em vez de 10
    
    float multipliedValue = f * (1 << fractional_bits);
    
    int roundedValue;

    // arrendondando valor
    if (multipliedValue >= 0) {
        roundedValue = multipliedValue + 0.5f;
    } else {
        roundedValue = multipliedValue - 0.5f;
    }

    fixed_point_value = roundedValue;
}

float   Fixed::toFloat(void) const {

}

int     Fixed::toInt(void) const {

}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {

}
