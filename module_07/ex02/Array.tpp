#include "Array.hpp"

// constructor empty array
template <typename T>
Array<T>::Array(void) : array(NULL), len(0) {}

// constructor n elements array
template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), len(n) {}

// copy constructor - deep copy
template <typename T>
Array<T>::Array(const Array<T>& other) : array(NULL), len(0) {
    *this = other;
}

// copy assignment operator - deep copy
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) { 
    if (this != &other){
        delete[] this->array;
        this->len = other.len;
        this->array = new T[other.len];
        for (size_t i = 0; i < this->len; i++)
            this->array[i] = other.array[i];
    } 
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index < 0 || index >= len)
        throw std::out_of_range("Index out of bounds.");
    return (this->array[index]);
}

template <typename T>
Array<T>::~Array(void) {
    delete[] this->array;
}

template <typename T>
size_t Array<T>::size(void) const{
    return (this->len);
}