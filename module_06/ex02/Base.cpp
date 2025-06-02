#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void) {

    static bool rand_exist = false;

    // seed the random generator
    if (!rand_exist) {
        std::srand(std::time(0));
        rand_exist = true;
    }

    int random = std::rand() % 3;
    
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void    identify(Base* p) {

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception&) {
        //std::cout << "(not A type)" << std::endl;
    }

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (std::exception&) {
        //std::cout << "(not B type)" << std::endl;
    }

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::exception&) {
        //std::cout << "(not C type)" << std::endl;
    }
}
