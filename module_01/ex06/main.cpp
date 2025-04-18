#include "Harl.hpp"

int main(int ac, char **av) {

    if (ac != 2) {
        std::cerr << "Error: Wrong number of arguments." << std::endl;
        std::cerr << "Usage: " << av[0] << " <Comment Level>" << std::endl;
        return 1;
    }
    Harl Robot_Harl;
    Robot_Harl.complain(av[1]);

    return 0;
}