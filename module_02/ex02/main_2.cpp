#include "Fixed.hpp"

int main() {

    std::cout << "=== Fixed Point Class ===\n\n";

    // --- Constructors ---
    std::cout << "[1] Testing constructors:\n";
    Fixed a;                         // Default constructor
    Fixed b(5);                      // Construct from int
    Fixed c(2.5f);                   // Construct from float
    Fixed d = b;                     // Copy constructor
    Fixed e;                         // Default, then copy-assigned
    e = c;

    std::cout << "Fixed a (default)         = " << a << " | Expected: 0.0\n";
    std::cout << "Fixed b (int 5)           = " << b << " | Expected: 5.0\n";
    std::cout << "Fixed c (float 2.5f)      = " << c << " | Expected: 2.5\n";
    std::cout << "Fixed d (copy of b)       = " << d << " | Expected: 5.0\n";
    std::cout << "Fixed e (assigned from c) = " << e << " | Expected: 2.5\n\n";

    // --- Arithmetic Operations ---
    std::cout << "[2] Testing arithmetic operators:\n";
    Fixed sum = b + c;
    Fixed diff = b - c;
    Fixed prod = b * c;
    Fixed quot = b / c;

    std::cout << b << " + " << c << " = " << sum << " | Expected: 7.5\n";
    std::cout << b << " - " << c << " = " << diff << " | Expected: 2.5\n";
    std::cout << b << " * " << c << " = " << prod << " | Expected: 12.5\n";
    std::cout << b << " / " << c << " = " << quot << " | Expected: 2.0\n\n";

    // --- Comparison Operators ---
    std::cout << "[3] Testing comparison operators:\n";
    std::cout << b << " > " << c << " : " << (b > c ? "true" : "false") << " | Expected: true\n";
    std::cout << b << " < " << c << " : " << (b < c ? "true" : "false") << " | Expected: false\n";
    std::cout << b << " >= " << d << " : " << (b >= d ? "true" : "false") << " | Expected: true\n";
    std::cout << b << " <= " << d << " : " << (b <= d ? "true" : "false") << " | Expected: true\n";
    std::cout << b << " == " << d << " : " << (b == d ? "true" : "false") << " | Expected: true\n";
    std::cout << c << " != " << e << " : " << (c != e ? "true" : "false") << " | Expected: false\n\n";

    // --- Increment/Decrement ---
    std::cout << "[4] Testing increment/decrement operators:\n";
    Fixed x;
    std::cout << "Initial x                = " << x << " | Expected: 0.0\n";
    std::cout << "Pre-increment   ++x      = " << ++x << " | Expected: ~0.00390625\n";
    std::cout << "Post-increment  x++      = " << x++ << " | Expected: same as previous (~0.00390625)\n";
    std::cout << "x after post-increment   = " << x << " | Expected: ~0.0078125\n";
    std::cout << "Pre-decrement   --x      = " << --x << " | Expected: ~0.00390625\n";
    std::cout << "Post-decrement  x--      = " << x-- << " | Expected: ~0.00390625\n";
    std::cout << "x after post-decrement   = " << x << " | Expected: 0.0\n\n";

    // --- Raw Bit Access ---
    std::cout << "[5] Testing raw bit access:\n";
    std::cout << "Raw bits of c (" << c << ") = " << c.getRawBits() << " | Expected: (int)(2.5 * 256) = 640\n";
    std::cout << "Raw bits of b (" << b << ") = " << b.getRawBits() << " | Expected: (int)(5 * 256) = 1280\n";
    std::cout << "Setting raw bits of a to 1024...\n";
    a.setRawBits(1024);
    std::cout << "a after setRawBits       = " << a << " | Expected: 1024 / 256 = 4.0\n\n";

    // --- Min/Max ---
    std::cout << "[6] Testing min and max static functions:\n";
    Fixed f(10.5f);
    Fixed g(42.42f);
    std::cout << "f = " << f << ", g = " << g << "\n";
    std::cout << "min(f, g) = " << Fixed::min(f, g) << " | Expected: 10.5\n";
    std::cout << "max(f, g) = " << Fixed::max(f, g) << " | Expected: 42.42\n";

    const Fixed h(99.99f);
    const Fixed i(0.01f);
    std::cout << "h = " << h << ", i = " << i << " (const)\n";
    std::cout << "min(h, i) = " << Fixed::min(h, i) << " | Expected: 0.01\n";
    std::cout << "max(h, i) = " << Fixed::max(h, i) << " | Expected: 99.99\n";

    std::cout << "\n=== End of Test ===\n";
    return 0;
}
