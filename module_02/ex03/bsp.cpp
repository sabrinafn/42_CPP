#include "Fixed.hpp"
#include "Point.hpp"

Fixed   getTriangleArea(Point const a, Point const b, Point const c) {

    //area = 0.5 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
    Fixed result = (a.getX() * (b.getY() - c.getY()) +
                    b.getX() * (c.getY() - a.getY()) +
                    c.getX() * (a.getY() - b.getY()));

    if (result < Fixed(0))
        result = result * Fixed(-1);
    
    return result / Fixed(2);
}

bool isOnEdge(Point const &a, Point const &b, Point const &point) {

    Fixed area = getTriangleArea(a, b, point);

    // checks if there's no area, because they're all in the same line
    // return false because they're not all in the same line
    if (area > Fixed(0.001f) || area < Fixed(-0.001f)) {

        std::cout << "area != fixed[0]1" << std::endl;
        return false;
    }
    // checks if it is between two vertices, it will check if 
    // the value is between the value of the edges
    if (point.getX() >= std::min(a.getX(), b.getX())
        && point.getX() <= std::max(a.getX(), b.getX())
        && point.getY() >= std::min(a.getY(), b.getY())
        && point.getY() <= std::max(a.getY(), b.getY())) {
            std::cout << "true inside two bertice isonedge" << std::endl;
        return true;
    }
    std::cout << "here last false inside isonedge" << std::endl;
    return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    if (isOnEdge(a, b, point) || isOnEdge(b, c, point) || isOnEdge(c, a, point)) {
        
        std::cout << "point is on the edge" << std::endl;
        return false;
    }
    // 1. calculate area of a triangle using vertex coordinates
    Fixed   area(getTriangleArea(a, b, c));
    (void)point;

    Fixed area_1 = getTriangleArea(point, b, c);
    Fixed area_2 = getTriangleArea(a, point, c);
    Fixed area_3 = getTriangleArea(a, b, point);

    Fixed sum = area_1 + area_2 + area_3;

    std::cout << std::endl;
    std::cout << "Area ABC: " << area << std::endl;
    std::cout << "Area PBC: " << area_1 << std::endl;
    std::cout << "Area APC: " << area_2 << std::endl;
    std::cout << "Area ABP: " << area_3 << std::endl;
    std::cout << "Sum:      " << sum << std::endl;

    if (sum != area) {
        std::cout << "sum != triangle_area" << std::endl;
        return false;
    }
    
    std::cout << "sum == triangle_area" << std::endl;

    return true;
}