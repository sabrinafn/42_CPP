#include "Serializer.hpp"

int main(void){

    Data* ptr = new Data;

    uintptr_t raw = Serializer::serialize(ptr);

    Data* ptr_new = Serializer::deserialize(raw);

    std::cout << "Original pointer:   " << ptr << std::endl; // hex
    std::cout << "Serialized value:   " << raw << std::endl; // same address but converted to a type int 
                                                             // decimal
    std::cout << "Deserialized ptr:   " << ptr_new << std::endl; // hex

    if (ptr == ptr_new)
        std::cout << "\nThe return value of deserialize() "
                  << "is equal to the original pointer "
                  << "passed to serialize()." << std::endl;
    else
        std::cout << "Pointers do not match!" << std::endl;

    delete ptr;
    return 0;
}