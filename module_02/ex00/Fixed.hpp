#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"

class Fixed {

    private:
        int                 fixed_point_value;
        static const int    fractional_bits = 8;

    public:
        Fixed(); // constructor
        Fixed(const Fixed &other); // copy constructor
        Fixed &operator=(const Fixed &other); // copy assignment operator overload
        ~Fixed(); // destructor
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

};

#endif