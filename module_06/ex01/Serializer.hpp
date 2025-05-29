#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
    
    private:
        Serializer(void); // constructor
        Serializer(const Serializer &other); // copy constructor
        Serializer& operator=(const Serializer &other); // copy assignment operator
        ~Serializer(void); // destructor
    
    public:
        // It takes a pointer and converts it to the unsigned integer type uintptr_t
        static uintptr_t serialize(Data* ptr);
        
        // It takes an unsigned integer parameter and converts it to a pointer to Data
        static Data* deserialize(uintptr_t raw);
};

#endif