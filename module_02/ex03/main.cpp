#include <iostream>
#include "Point.hpp"  // Assuming you have your Point class and bsp function in this header.

int main() {
    // Test 1: A point inside the triangle
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point point1(1, 1);  // Point inside the triangle
/*
    std::cout << "Test 1 (Inside Triangle): "
              << (bsp(a, b, c, point1) ? "Inside" : "Outside") << std::endl;

    // Test 2: A point on the edge of the triangle
    Point point2(2, 0);  // Point on the edge of the triangle (between a and b)
    
    std::cout << "Test 2 (On Edge): "
              << (bsp(a, b, c, point2) ? "Inside" : "Outside") << std::endl;

    // Test 3: A point at a vertex of the triangle
    Point point3(0, 0);  // Point is vertex a
    
    std::cout << "Test 3 (At Vertex): "
              << (bsp(a, b, c, point3) ? "Inside" : "Outside") << std::endl;

    // Test 4: A point outside the triangle
    Point point4(6, 6);  // Point outside the triangle
    
    std::cout << "Test 4 (Outside Triangle): "
              << (bsp(a, b, c, point4) ? "Inside" : "Outside") << std::endl;

    // Test 5: A point on a non-right triangle
    Point d(0, 0);
    Point e(4, 0);
    Point f(2, 3);
    Point point5(1, 1);  // Point inside the triangle

    std::cout << "Test 5 (Inside Non-Right Triangle): "
              << (bsp(d, e, f, point5) ? "Inside" : "Outside") << std::endl;

    // Test 6: Point outside a non-right triangle
    Point point6(5, 5);  // Point outside the triangle

    std::cout << "Test 6 (Outside Non-Right Triangle): "
              << (bsp(d, e, f, point6) ? "Inside" : "Outside") << std::endl;
*/
    // Test 7: Testing a larger triangle
    Point g(0, 0);
    Point h(10, 0);
    Point i(0, 10);
    Point point7(5, 5);  // Point inside the larger triangle

    std::cout << "Test 7 (Inside Larger Triangle): "
              << (bsp(g, h, i, point7) ? "Inside" : "Outside") << std::endl;

    // Test 8: Point outside the larger triangle
    Point point8(15, 15);  // Point outside the larger triangle

    std::cout << "Test 8 (Outside Larger Triangle): "
              << (bsp(g, h, i, point8) ? "Inside" : "Outside") << std::endl;

    // Test 9: Testing a degenerate triangle (points are collinear)
    Point j(0, 0);
    Point k(5, 5);
    Point l(10, 10);
    Point point9(7, 7);  // Point on the line of the degenerate triangle

    std::cout << "Test 9 (On Line of Degenerate Triangle): "
              << (bsp(j, k, l, point9) ? "Inside" : "Outside") << std::endl;

    return 0;
}
