#include "Array.hpp"
#include "Array.tpp"
#include <sstream>
#define max_size 5

int main(int, char**)
{   
    // SCOPE FOR INT ARRAY
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

        std::cout << "Trying to access position [-2] in myArrays2: " << std::endl;
        try
        {
            myArrays2[-2] = 0;
            std::cout << "Acessed position [-2] in myArrays2." << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << "\nTrying to access position [max_size] in myArrays2: " << std::endl;
        try
        {
            myArrays2[max_size] = 0;
            std::cout << "Acessed position [max_size] in myArrays2." << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << "\n\n";
        }

        for (int i = 0; i < max_size; i++)
            myArrays2[i] = num++;

        std::cout << "Array<int>myArrays2 updated with new values: " << std::endl;
        for (int i = 0; i < max_size; i++) {
            std::cout << "[" << i << "]: " << myArrays2[i] << " ";
        }
        std::cout << "\n" << std::endl;

    }

    /*****************************************************************************/

    // SCOPE FOR STRING ARRAY
    {
        Array<std::string> myStringArray(max_size);
        std::string word = "Word_";

        // Preenchendo o array com strings
        for (int i = 0; i < max_size; i++) {
            std::stringstream ss;
            ss << i;
            myStringArray[i] = word + ss.str();
        }

        std::cout << "Array<std::string> myStringArray created with values:\n";
        for (int i = 0; i < max_size; i++) {
            std::cout << "[" << i << "]: " << myStringArray[i] << " ";
        }
        std::cout << "\n\n";

        // Testando cópia profunda
        Array<std::string> myStringCopy = myStringArray;
        Array<std::string> test(myStringCopy);

        std::cout << "Array<std::string> myStringCopy (=operator):\n";
        for (int i = 0; i < max_size; i++) {
            std::cout << "[" << i << "]: " << myStringCopy[i] << " ";
        }
        std::cout << "\n\n";

        std::cout << "Array<std::string> test (copy constructor):\n";
        for (int i = 0; i < max_size; i++) {
            std::cout << "[" << i << "]: " << test[i] << " ";
        }
        std::cout << "\n";
    }
} 

/*
// subject main

#include <iostream>
#include <Array.hpp>
#include <Array.tpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
*/