#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <sstream> 
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int value) {

    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end()) {
        std::stringstream ss;
        ss << value;
        throw std::runtime_error("Element [" + ss.str() + "] not found in container.");
    }
    return it;
};

template <typename T>
void printContainer(const T& container) {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
};

#endif