#include "Replacer.hpp"

int main(int ac, char **av) {

    if (ac == 4)
    {
        std::cout << "av[1] = " << av[1] << std::endl;
    }
    else
    {
        std::cerr << "Error: Wrong number of arguments." << std::endl;
        std::cerr << "Usage: " << av[0] << " <filename> <string_to_find> <string_to_replace>" << std::endl;
        return 1;
    }
    return 0;
}