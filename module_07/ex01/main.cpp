#include "iter.hpp"

int main(void) {
    
    // std::string array
    {
        std::cout << "=== Creating std::string array..." << std::endl;
        std::string str[4] = {"one", "two", "three", "four"};
        std::cout << "std::string str[4] = {\"one\", \"two\", \"three\", \"four\"};\n" << std::endl;

        // array length
        size_t string_len = sizeof(str) / sizeof(str[0]);

        std::cout << "=== Values found in std::string array using function iter:" << std::endl;
        // iter function
        ::iter(str, string_len, printArray);
    }
    
    // int array
    {
        std::cout << "\n=== Creating int array..." << std::endl;
        int arr[4] = {4, 3, 2, 1};
        std::cout << "int arr[4] = {4, 3, 2, 1};\n" << std::endl;

        // array length
        size_t arr_len = sizeof(arr) / sizeof(arr[0]);

        std::cout << "=== Values found in int array using function iter:" << std::endl;
        // iter function
        ::iter(arr, arr_len, printArray);
    }
    return 0;
}