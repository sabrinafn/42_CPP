#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data {
    int i;
};

class Serializer {
    
    private:
        Serializer(void); // constructor
        Serializer(const Serializer &other); // copy constructor
        Serializer& operator=(const Serializer &other); // copy assignment operator
        ~Serializer(void); // destructor
    
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif