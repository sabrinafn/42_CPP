#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   Base::generate(void) {

    static bool rand_exist = false;

    // seed the random generator
    if (!rand_exist) {
        std::srand(std::time(0));
        rand_exist = true;
    }

    int random = std::rand();
    
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