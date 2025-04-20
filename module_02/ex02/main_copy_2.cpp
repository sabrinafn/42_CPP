#include "Fixed.hpp"

/*
int main() {

    Fixed ValueA(10.5f);
    Fixed ValueB(2.0f);
    
    std::cout << "==================================" << std::endl;
    std::cout << " Value A: " << ValueA;
    std::cout << "      Value B: " << ValueB << std::endl;
    std::cout << "==================================" << std::endl;
  
    std::cout << " Math" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << " A + B = " << ValueA + ValueB << std::endl;
    std::cout << " A - B = " << ValueA - ValueB << std::endl;
    std::cout << " A * B = " << ValueA * ValueB << std::endl;
    std::cout << " A / B = " << ValueA / ValueB << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;

    std::cout << "==================================" << std::endl;
    std::cout << " Value A: " << ValueA;
    std::cout << "      Value B: " << ValueB << std::endl;
    std::cout << "==================================" << std::endl;

    std::cout << " Comparison" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << " A > B = " << (ValueA > ValueB) << std::endl;
    std::cout << " A < B = " << (ValueA < ValueB) << std::endl;
    std::cout << " A >= B = " << (ValueA >= ValueB) << std::endl;
    std::cout << " A <= B = " << (ValueA <= ValueB) << std::endl;
    std::cout << " A == B = " << (ValueA == ValueB) << std::endl;
    std::cout << " A != B = " << (ValueA != ValueB) << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;
  
    Fixed ValueC(5.0f);
    Fixed ValueD(5.0f);

    std::cout << "==================================" << std::endl;
    std::cout << " Value C: " << ValueC;
    std::cout << "      Value D: " << ValueD << std::endl;
    std::cout << "==================================" << std::endl;

    std::cout << " Increment and Decrement" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << " C = " << ValueC << std::endl;
    std::cout << " C++ = " << ValueC++ << std::endl; // Pós-incremento
    std::cout << " C = " << ValueC << std::endl;
    std::cout << " ++C = " << ++ValueC << std::endl; // Pré-incremento
    std::cout << " C = " << ValueC << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << " D = " << ValueD << std::endl;
    std::cout << " D-- = " << ValueD-- << std::endl; // Pós-decremento
    std::cout << " D = " << ValueD << std::endl;
    std::cout << " --D = " << --ValueD << std::endl; // Pré-decremento
    std::cout << " D = " << ValueD << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;




    Fixed ValueE(42.42f);
    Fixed ValueF(21.21f);

    std::cout << "==================================" << std::endl;
    std::cout << " Value E: " << ValueE;
    std::cout << "  Value F: " << ValueF << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << " Min/Max" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << " min(E, F) = " << Fixed::min(ValueE, ValueF) << std::endl;
    std::cout << " max(E, F) = " << Fixed::max(ValueE, ValueF) << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;


    const Fixed ConstValueG(42.42f);
    const Fixed ConstValueH(21.21f);

    std::cout << "==================================" << std::endl;
    std::cout << " Value G: " << ConstValueG;
    std::cout << "  Value H: " << ConstValueH << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << " Min/Max Const Value" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << " min(G, H) = " << Fixed::min(ConstValueG, ConstValueH) << std::endl;
    std::cout << " max(G, H) = " << Fixed::max(ConstValueG, ConstValueH) << std::endl;
    std::cout << "==================================" << std::endl;

    return 0;
  }
*/

int main(void) {

    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}