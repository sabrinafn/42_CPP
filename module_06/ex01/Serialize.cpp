#include "Serialize.hpp"

// constructor
Serializer::Serializer(void) {}

// copy constructor
Serializer::Serializer(const Serializer &other) { (void)other; }

// copy assignment operator
Serializer& Serializer::operator=(const Serializer &other) { (void)other; return *this;}

// destructor
Serializer::~Serializer(void) {} 


// It takes a pointer and converts it to the unsigned integer type uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

// It takes an unsigned integer parameter and converts it to a pointer to Data
Data* Serializer::deserialize(uintptr_t raw) {
    Data* ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}