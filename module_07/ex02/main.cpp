#include "Array.hpp"
#include "Array.tpp"

#define max_size 5

int main(int, char**)
{   
    Array<int> myArrays2(max_size);
    int num = 123;
    for (int i = 0; i < max_size; i++) {
        myArrays2[i] = num++;
    }
    
    std::cout << "Array<int>myArrays2 created with values: " << std::endl;
    for (int i = 0; i < max_size; i++) {
        std::cout << "[" << i << "]: " << myArrays2[i] << " ";
    }
    std::cout << "\n" << std::endl;

    Array<int> myArrayDeepCopy = myArrays2;
    Array<int> test(myArrayDeepCopy);
    
    std::cout << "Array<int>myArrayDeepCopy (=operator) created with values: " << std::endl;
    for (int i = 0; i < max_size; i++) {
        std::cout << "[" << i << "]: " << myArrayDeepCopy[i] << " ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "Array<int>test (copy constructor) created with values: " << std::endl;
    for (int i = 0; i < max_size; i++) {
        std::cout << "[" << i << "]: " << test[i] << " ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "Trying to access position -2"
    try
    {
        myArrays2[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        myArrays2[max_size] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < max_size; i++)
    {
        myArrays2[i] = num++;
    }
    return 0;
}