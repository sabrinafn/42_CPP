#include "iter.hpp"

int main(void) {
    
    // array
    std::cout << "=== Creating std::string array..." << std::endl;
    std::string str[4] = {"one", "two", "three", "four"};
    std::cout << "std::string str[4] = {\"one\", \"two\", \"three\", \"four\"};\n" << std::endl;

    // array length
    size_t string_len = sizeof(str) / sizeof(str[0]);

    std::cout << "=== Values found in std::string array using function iter:" << std::endl;
    // iter function
    ::iter(str, string_len, printArray);
    
    return 0;
}