#include "Point.hpp"

Point::Point() : x(0), y(0) {
    std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Point&  Point::operator=(const Point &other) {

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
    }
    return *this;
}

Point::~Point() {
    std::cout << "Destructor called" << std::endl;
}

Point::Point(const float a, const float b) : x(a), y(b){
    std::cout << "two floats Constructor called" << std::endl;
}

Fixed   Point::getX() const {
    return this->x;
}

Fixed   Point::getY() const {
    return this->y;
}


std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.getX() << ", " << point.getY() << ")";
    return out;
  }