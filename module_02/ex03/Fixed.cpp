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

// ============================ same as ex00 ================================ //

// DEFAULT CONSTRUCTOR
Fixed::Fixed() : fixed_point_value(0) {

  //std::cout << "Default constructor called" << std::endl;
}

// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed &other) {

  //std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

// COPY ASSIGNMENT OPERATOR OVERLOAD
Fixed&  Fixed::operator=(const Fixed &other) {

  //std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) // check if it is not assigning to itself
    fixed_point_value = other.getRawBits();
  return *this; // Return a reference to the current object
}

// DESTRUCTOR
Fixed::~Fixed() {

  //std::cout << "Destructor called" << std::endl;
}

// METHOD TO GET THE FIXED-POINT VALUE
int     Fixed::getRawBits(void) const {

  //std::cout << "getRawBits member function called" << std::endl;
  return fixed_point_value;
}

// SETS THE FIXED-POINT VALUE
void    Fixed::setRawBits(int const raw) {

  fixed_point_value = raw;
}

// ============================ same as ex01 ================================ //

// CONSTRUCTOR THAT RECEIVES A CONSTANT INTEGER AS PARAMETER
Fixed::Fixed(const int n) {
  
  //std::cout << "Int constructor called" << std::endl;
  this->fixed_point_value = n << this->fractional_bits;
}

// CONSTRUCTOR THAT RECEIVES A CONSTANT FLOATING-POINT AS PARAMETER
Fixed::Fixed(const float f) {

//std::cout << "Float constructor called" << std::endl;
this->fixed_point_value = roundf(f * 256);
}

// METHOD THAT CONVERTS THE FIXED-POINT VALUE
// TO A FLOATING-POINT VALUE
float   Fixed::toFloat(void) const {

  return((float)this->fixed_point_value / 256);
}

// METHOD THAT CONVERTS THE FIXED-POINT VALUE
// TO A INTEGER VALUE
int     Fixed::toInt(void) const {

  return(this->fixed_point_value >> fractional_bits);
}

// An overload of the insertion («) operator that inserts a
// floating-point representation of the fixed-point number 
// into the output stream object passed as parameter.
// define como um objeto Fixed deve ser printado quando o
// operador '<<' é usado.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat(); // Converte para float e insere no stream
  return out;
}

// ============================ same as ex02 ================================ //

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
