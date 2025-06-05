#include "easyfind.hpp"

int main(void) {

    std::vector<int> container;
    
    container.push_back(0);
    container.push_back(8);
    container.push_back(4);
    container.push_back(6);
    container.push_back(8);

    try {
        std::vector<int>::iterator it = easyfind(container, 8);
        std::cout << "Element [" << *it << "] found in container." << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

        std::vector<int> container;
    
    container.push_back(0);
    container.push_back(8);
    container.push_back(4);
    container.push_back(6);
    container.push_back(8);

    try {
        std::vector<int>::iterator it = easyfind(container, 8);
        std::cout << "Element [" << *it << "] found in container." << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}