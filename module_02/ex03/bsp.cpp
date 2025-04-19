#include "Fixed.hpp"
#include "Point.hpp"

Fixed   getTriangleArea(Point const a, Point const b, Point const c) {

    //Área = 0.5 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
    Fixed half(0.5f);
    Fixed area(half * (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())));

    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    // 1. calculate area of a triangle using vertex coordinates
    Fixed   triangle_area(getTriangleArea(a, b, c));

    // find area of triangles related to point P
    // sum the 3 triangles
    // if 3 triangles == original triangle area
    // then P inside triangle
}