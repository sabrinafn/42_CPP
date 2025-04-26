#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {

    private:
        const Fixed    x;
        const Fixed    y;
        Point &operator=(const Point &other); // copy assignment operator overload
        // I wrote an empty assignment operator because Point has const attributes (x and y),
        // so it cannot be reassigned after construction. I still had to declare the operator
        // so it is according to the Orthodox Canonical Form
        
    public:
        Point(); // default constructor
        Point(const Point &other); // copy constructor
        ~Point(); // destructor
        
        Point(const float a, const float b); // constructor takes two constant floating-point numbers
      
        bool operator==(const Point &other) const;

        Fixed   getX() const;
        Fixed   getY() const;
};

std::ostream &operator<<(std::ostream &out, const Point &point);

bool    bsp( Point const a, Point const b, Point const c, Point const point);
Fixed   getTriangleArea(Point const a, Point const b, Point const c);

// https://www.desmos.com/calculator/9uufufvvdz?lang=pt-BR

#endif