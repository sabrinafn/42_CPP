#include "Array.hpp"

// constructor empty array
template <typename T>
Array<T>::Array(void) : array(NULL), size(0) {}

// constructor n elements array
template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), size(n) {}

// copy constructor - deep copy
template <typename T>
Array<T>::Array(const Array<T>& other) : array(NULL), size(0) {
    *this = other;
}

// copy assignment operator - deep copy
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) { 
    if (*this != other){
        delete[] this->array;
        this->array = new T[this->size];
        this->size = other.size;
        for (size_t i = 0; i < this->size; i++) {
            this->array[i] = other.array[i];
        }
    } 
    return *this;
}

T& operator[](size_t index) {
    
}