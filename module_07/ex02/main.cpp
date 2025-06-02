#include "Array.hpp"
#include "Array.tpp"

int main(int, char**)
{   
    Array<int> myArrays2(10);
    int num = 123;
    for (int i = 0; i < 10; i++) {
        myArrays2[i] = num++;
    }
    
    std::cout << "Array<int>myArrays2 created with values: " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "[" << i << "]: " << myArrays2[i] << std::endl;
    }


    Array<int> myArrayDeepCopy = myArrays2;
    Array<int> test(myArrayDeepCopy);
    
    std::cout << "Array<int>myArrayDeepCopy created with values: " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "[" << i << "]: " << myArrayDeepCopy[i] << std::endl;
    }

    std::cout << "Array<int>test created with values: " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "[" << i << "]: " << test[i] << std::endl;
    }

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
        myArrays2[10] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < 10; i++)
    {
        myArrays2[i] = num++;
    }
    return 0;
}