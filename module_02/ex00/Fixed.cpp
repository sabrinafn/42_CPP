/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:57:55 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/24 14:57:58 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0) {

    std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed &other) {

    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy Assignment Operator Overload
Fixed&  Fixed::operator=(const Fixed &other) {

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // check if it is not assigning to itself
      fixed_point_value = other.getRawBits();
    return *this; // Return a reference to the current object
}

Fixed::~Fixed() {

    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const {

    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point_value;
}

void    Fixed::setRawBits(int const raw) {

    fixed_point_value = raw;

}
