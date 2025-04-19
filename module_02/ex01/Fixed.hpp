#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    private:
        int                 fixed_point_value;
        static const int    fractional_bits = 8;

    public:
        Fixed(); // default constructor
        Fixed(const Fixed &other); // copy constructor
        Fixed &operator=(const Fixed &other); // copy assignment operator overload
        ~Fixed(); // destructor
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        Fixed(const int n); // constructor with const int
        Fixed(const float f); // constructor with const float
        
        float   toFloat(void) const;
        int     toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif