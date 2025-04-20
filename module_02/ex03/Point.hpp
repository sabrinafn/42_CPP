#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {

    private:
        const Fixed    x;
        const Fixed    y;
        
    public:
        Point(); // default constructor
        Point(const Point &other); // copy constructor
        Point &operator=(const Point &other); // copy assignment operator overload
        ~Point(); // destructor

        Point(const float a, const float b); // constructor takes two constant floating-point numbers
      
        Fixed   getX() const;
        Fixed   getY() const;
};

std::ostream &operator<<(std::ostream &out, const Point &point);

bool    bsp( Point const a, Point const b, Point const c, Point const point);
Fixed   getTriangleArea(Point const a, Point const b, Point const c);

#endif