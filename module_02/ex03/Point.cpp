#include "Point.hpp"


// CONSTRUCTOR
Point::Point() : x(0), y(0) {
    //std::cout << "Default constructor called" << std::endl;
}

// COPY CONSTRUCTOR
Point::Point(const Point &other) : x(other.x), y (other.y){
    //std::cout << "Copy constructor called" << std::endl;
}

// COPY ASSIGNMENT OPERATOR
Point&  Point::operator=(const Point &other) {
    (void)other;
    return *this;
}

// DESTRUCTOR
Point::~Point() {
    //std::cout << "Destructor called" << std::endl;
}

// CONSTRUCTOR THAT RECEIVES TWO FLOATS
Point::Point(const float a, const float b) : x(a), y(b){
    //std::cout << "two floats Constructor called" << std::endl;
}

// --- GETTERS ---

Fixed   Point::getX() const {
    return this->x;
}

Fixed   Point::getY() const {
    return this->y;
}


// Operator '=' overload to print object point like this: (x, y)
std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.getX() << ", " << point.getY() << ")";
    return out;
}

//Operator '==' overload to compare point object
bool Point::operator==(const Point &other) const {

    if (this->x != other.x)
        return false;
    if (this->y != other.y)
        return false;
    return true;
  }