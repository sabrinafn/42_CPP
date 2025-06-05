#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
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

#endif