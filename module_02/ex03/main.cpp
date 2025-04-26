#include <iostream>
#include "Point.hpp"  // Assuming you have your Point class and bsp function in this header.

void run_test(const Point &a, const Point &b, const Point &c, const Point &p, const std::string &desc) {
    std::cout << desc << ": " << (bsp(a, b, c, p) ? "Inside" : "Outside") << std::endl;
}

int main() {
    Point a(0, 0), b(5, 0), c(0, 5);
    run_test(a, b, c, Point(1, 1), "Test 1 (Inside Triangle)");
    run_test(a, b, c, Point(2, 0), "Test 2 (On Edge)");
    run_test(a, b, c, Point(0, 0), "Test 3 (At Vertex)");
    run_test(a, b, c, Point(6, 6), "Test 4 (Outside Triangle)");

    Point d(0, 0), e(4, 0), f(2, 3);
    run_test(d, e, f, Point(1, 1), "Test 5 (Inside Non-Right Triangle)");
    run_test(d, e, f, Point(5, 5), "Test 6 (Outside Non-Right Triangle)");

    Point g(0, 0), h(10, 0), i(0, 10);
    run_test(g, h, i, Point(5, 5), "Test 7 (On Edge of Larger Triangle)");
    run_test(g, h, i, Point(15, 15), "Test 8 (Outside Larger Triangle)");

    Point j(0, 0), k(5, 5), l(10, 10);
    run_test(j, k, l, Point(7, 7), "Test 9 (On Line of Degenerate Triangle)");

    return 0;
}