#include "whatever.hpp"

int main( void ) {

    // INT
    {
        std::cout << "Testing with type INT:" << std::endl;
        std::cout << "Original values: a = 2, b = 3" << std::endl;
        int a = 2;
        int b = 3;
        ::swap<int>( a, b );
        std::cout << "Swapped values:  a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max<int>( a, b ) << "\n" << std::endl;
    }

    // STRING
    {
        std::cout << "Testing with type STRING:" << std::endl;
        std::cout << "Original values: c = chaine1, d = chaine2" << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap<std::string>(c, d);
        std::cout << "Swapped values:  c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << "\n" << std::endl;
    }

    // DOUBLE
    {
        std::cout << "Testing with type DOUBLE:" << std::endl;
        std::cout << "Original values: y = 42.42, x = 3.14" << std::endl;
        double y = 42.42;
        double x = 3.14;
        ::swap<double>( y, x );
        std::cout << "Swapped values:  y = " << y << ", x = " << x << std::endl;
        std::cout << "min( y, x ) = " << ::min<double>( y, x ) << std::endl;
        std::cout << "max( y, x ) = " << ::max<double>( y, x ) << std::endl;
    }
    
    return 0;
}