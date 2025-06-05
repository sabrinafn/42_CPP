#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main(void) {
    {
        std::cout << "===== Vector container =====\n" << std::endl;
        std::vector<int> container;
        
        container.push_back(0);
        container.push_back(2);
        container.push_back(4);
        container.push_back(6);
        container.push_back(8);

        std::cout << "Vector values: ";
        printContainer(container);

        try {
            std::vector<int>::iterator it = easyfind(container, 8);
            std::cout << "Element [" << *it << "] found in container." << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::vector<int>::iterator it = easyfind(container, 1);
            std::cout << "Element [" << *it << "] found in container." << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    
    {
        std::cout << "\n===== Deque container =====\n" << std::endl;

        std::deque<int> container;
        container.push_back(10);
        container.push_back(20);
        container.push_back(63);
        container.push_back(-12);
        container.push_back(71);

        std::cout << "Deque values: ";
        printContainer(container);

        try {
            std::deque<int>::iterator it = easyfind(container, 63);
            std::cout << "Element [" << *it << "] found in container." << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::deque<int>::iterator it = easyfind(container, 11);
            std::cout << "Element [" << *it << "] found in container." << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
        
    {
        std::cout << "\n===== List container =====\n" << std::endl;

        std::list<int> container;
        container.push_back(123);
        container.push_back(234);
        container.push_back(345);
        container.push_back(456);
        container.push_back(567);

        std::cout << "list values: ";
        printContainer(container);

        try {
            std::list<int>::iterator it = easyfind(container, 123);
            std::cout << "Element [" << *it << "] found in container." << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::list<int>::iterator it = easyfind(container, 321);
            std::cout << "Element [" << *it << "] found in container." << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}