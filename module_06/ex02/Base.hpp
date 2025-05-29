#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <typeinfo>

class Base {
    public:
        Base(void) {}; 
        virtual ~Base(void) {}; // destructor
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif