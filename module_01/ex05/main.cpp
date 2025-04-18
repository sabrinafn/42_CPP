#include "Harl.hpp"

int main(void) {

    Harl Robot_Harl;
    Robot_Harl.complain("DEBUG");
    std::cout << std::endl;
    Robot_Harl.complain("INFO");
    std::cout << std::endl;
    Robot_Harl.complain("WARNING");
    std::cout << std::endl;
    Robot_Harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "--- Testing Invalid and Empty Inputs: ---"
    << std::endl << std::endl;
    
    Robot_Harl.complain("HELLO");
    std::cout << std::endl;
    Robot_Harl.complain("");
    std::cout << std::endl;

    return 0;
}