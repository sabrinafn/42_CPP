#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
    public:
        virtual ~Base(void); // destructor
        Base*   generate(void);
        void    identify(Base* p);
        void    identify(Base& p);
};

#endif