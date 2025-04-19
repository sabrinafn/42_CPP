#include "Fixed.hpp"

// DEFAULT CONSTRUCTOR
Fixed::Fixed() {

    //std::cout << "Default constructor called" << std::endl;
    this->fixed_point_value = 0;
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
      this->fixed_point_value = other.fixed_point_value;

    return *this; // Return a reference to the current object
}

// DESTRUCTOR
Fixed::~Fixed() {

    //std::cout << "Destructor called" << std::endl;
}

// CONSTRUCTOR THAT RECEIVES A CONST INT AS PARAMETER
Fixed::Fixed(const int n) {

    // bitwise operator to move bits to the left
    // 5 = 00000101
    // n << fractional_bits = 0000010100000000
    //std::cout << "Int constructor called" << std::endl;
    this->fixed_point_value = n << this->fractional_bits;
}

// CONSTRUCTOR THAT RECEIVES A CONST FLOAT AS PARAMETER
Fixed::Fixed(const float f) {

	//std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = roundf(f * 256);
}

// METHOD TO GET THE FIXED-POINT VALUE
int     Fixed::getRawBits(void) const {

    //std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point_value;
}

// SETS THE FIXED-POINT VALUE
void    Fixed::setRawBits(int const raw) {

    //std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point_value = raw;
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

//An overload of the insertion («) operator that inserts a
// floating-point representation of the fixed-point number 
//into the output stream object passed as parameter
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat(); // Converte para float e insere no stream
    return out;

}

// operator overloading comparison functions

bool    Fixed::operator>(const Fixed &other) const {

    return fixed_point_value > other.fixed_point_value;
}

bool    Fixed::operator<(const Fixed &other) const {

    return fixed_point_value < other.fixed_point_value;
}

bool    Fixed::operator>=(const Fixed &other) const {

    return fixed_point_value >= other.fixed_point_value;
}

bool    Fixed::operator<=(const Fixed &other) const {

    return fixed_point_value <= other.fixed_point_value;
}

bool    Fixed::operator==(const Fixed &other) const {

    return fixed_point_value == other.fixed_point_value;
}

bool    Fixed::operator!=(const Fixed &other) const {

    return fixed_point_value != other.fixed_point_value;
}

// operator overloading arithmetic functions

Fixed   Fixed::operator+(const Fixed &other) const {

    Fixed result;
    result.fixed_point_value = fixed_point_value + other.fixed_point_value;
    
    return result;
}

Fixed   Fixed::operator-(const Fixed &other) const {

    Fixed result;
    result.fixed_point_value = fixed_point_value - other.fixed_point_value;
    
    return result;
}

Fixed   Fixed::operator*(const Fixed &other) const {
    
    Fixed result;
    // long para evitar overflow
    long temp = this->fixed_point_value * other.fixed_point_value;
    // dividir pelo resultado da operacao bitwise (1 << fractionalBits)
    result.fixed_point_value = (temp / (1 << this->fractional_bits));
    
    return result;
}

Fixed   Fixed::operator/(const Fixed &other) const {

    Fixed result;
    result.fixed_point_value = fixed_point_value / other.fixed_point_value;
    
    return result;
}

// operator overloading increment and decrement functions

Fixed   &Fixed::operator++() {

    fixed_point_value += 1;

    return *this;
}

Fixed   Fixed::operator++(int) {

    Fixed temp = *this;
    fixed_point_value += 1;
   
    return temp;
}

Fixed   &Fixed::operator--() {

    fixed_point_value -= 1;

    return *this;
}

Fixed   Fixed::operator--(int) {

    Fixed temp = *this;;
    fixed_point_value -= 1;
   
    return temp;
}

// min and max static functions

Fixed &Fixed::min(Fixed &a, Fixed &b) {

    return (a.fixed_point_value < b.fixed_point_value) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {

    return (a.fixed_point_value < b.fixed_point_value) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {

    return (a.fixed_point_value > b.fixed_point_value) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {

    return (a.fixed_point_value > b.fixed_point_value) ? a : b;
}

