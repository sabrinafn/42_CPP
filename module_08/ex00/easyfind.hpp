#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
void easyfind(T& container, int i) {

    std::vector<int>::iterator it;

    it = find(container.begin(), container.end(), i);

    if (it != container.end())
        std::cout << "element found in T container: " << *it << std::endl;
    else
        std::cout << "element not found in T container." << std::endl;
};

#endif