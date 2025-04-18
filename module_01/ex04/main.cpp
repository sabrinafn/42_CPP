#include "Replacer.hpp"

int main(int ac, char **av) {

    if (ac != 4)
    {
        std::cerr << "Error: Wrong number of arguments." << std::endl;
        std::cerr << "Usage: " << av[0] << " <filename> <string_to_find> <string_to_replace>" << std::endl;
        return 1;
    }

    Replacer replacerClass(av[1], av[2], av[3]);
    replacerClass.readFile();
    replacerClass.stringReplace();
    return 0;
}