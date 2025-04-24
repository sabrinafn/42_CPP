/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:58:52 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/24 14:58:54 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

// DEFAULT CONSTRUCTOR
Fixed::Fixed() : fixed_point_value(0) {}

// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed &other) : fixed_point_value(other.fixed_point_value) {}

// COPY ASSIGNMENT OPERATOR OVERLOAD
Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    fixed_point_value = other.fixed_point_value;
  }
  return *this;
}

// DESTRUCTOR
Fixed::~Fixed() {}

// CONSTRUCTOR THAT RECEIVES A CONST INT AS PARAMETER
Fixed::Fixed(const int n) : fixed_point_value(n << fractional_bits) {}

// CONSTRUCTOR THAT RECEIVES A CONST FLOAT AS PARAMETER
Fixed::Fixed(const float f) : fixed_point_value(roundf(f * (1 << fractional_bits))) {}

// METHOD TO GET THE FIXED-POINT VALUE
int Fixed::getRawBits(void) const { return fixed_point_value; }

// SETS THE FIXED-POINT VALUE
void Fixed::setRawBits(int const raw) { fixed_point_value = raw; }

// METHOD THAT CONVERTS THE FIXED-POINT VALUE
// TO A FLOATING-POINT VALUE
float Fixed::toFloat(void) const {
  return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}

// METHOD THAT CONVERTS THE FIXED-POINT VALUE
// TO A INTEGER VALUE
int Fixed::toInt(void) const { return fixed_point_value >> fractional_bits; }

// An overload of the insertion («) operator that inserts a
// floating-point representation of the fixed-point number
// into the output stream object passed as parameter
std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    //out << std::fixed << std::setprecision(8) << value.toFloat();
    return out;
}

// operator overloading comparison functions

bool Fixed::operator>(const Fixed &other) const {
  return fixed_point_value > other.fixed_point_value;
}

bool Fixed::operator<(const Fixed &other) const {
  return fixed_point_value < other.fixed_point_value;
}

bool Fixed::operator>=(const Fixed &other) const {
  return fixed_point_value >= other.fixed_point_value;
}

bool Fixed::operator<=(const Fixed &other) const {
  return fixed_point_value <= other.fixed_point_value;
}

bool Fixed::operator==(const Fixed &other) const {
  return fixed_point_value == other.fixed_point_value;
}

bool Fixed::operator!=(const Fixed &other) const {
  return fixed_point_value != other.fixed_point_value;
}

// operator overloading arithmetic functions
Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

// operator overloading increment and decrement functions

Fixed &Fixed::operator++() {
  fixed_point_value += 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  fixed_point_value += 1;
  return temp;
}

Fixed &Fixed::operator--() {
  fixed_point_value -= 1;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  fixed_point_value -= 1;
  return temp;
}

// min and max static functions

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return (a.toFloat() < b.toFloat()) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a.toFloat() < b.toFloat()) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return (a.toFloat() > b.toFloat()) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a.toFloat() > b.toFloat()) ? a : b;
}
