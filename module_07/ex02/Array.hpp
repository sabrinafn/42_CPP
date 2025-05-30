#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {

    private:
        T* array;
        size_t size;

    public:
        // constructor empty array
        T(void) : array(new T*){}

        // constructor n elements array
        T(unsigned int n) : array(T[n]) {}

        // copy constructor - deep copy
        T(const T& other) : array(other) {}

        // copy assignment operator - deep copy
        T& operator=(const T& other) { 
            if (*this != other){
                this->array = new other.array;
                this->size = new other.size;
            } 
            return *this;
        }

};

#endif