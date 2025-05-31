#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {

    private:
        T* array;
        size_t size;

    public:
        // constructor empty array
        Array(void);

        // constructor n elements array
        Array(unsigned int n);

        // copy constructor - deep copy
        Array(const T& other);

        // copy assignment operator - deep copy
        Array& operator=(const Array& other);

        // [] operator
        T& operator[](size_t index);
};

#endif