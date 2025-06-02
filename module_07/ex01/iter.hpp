#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&)) { // (address of an array, length of the array, function pointer)
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
};

template <typename T> 
void printArray(T& var) {
    std::cout << var << std::endl;
}


#endif