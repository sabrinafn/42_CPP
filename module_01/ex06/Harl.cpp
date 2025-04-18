#include "Harl.hpp"

void    Harl::debug(void) {

    std::cout << BG_WHITE << BLACK
    << "DEBUG:" << RESET
    << " Entering function; initial parameters are..."
    << std::endl;
}

void    Harl::info(void) {

    std::cout << BG_BLUE
    << "INFO:" << RESET
    << " Operation completed without errors; expected result."
    << std::endl;
}

void    Harl::warning(void) {
    
    std::cout << BG_MAGENTA
    << "WARNING:" << RESET
    << " Potential data loss or unexpected behavior may occur."
    << std::endl;
}

void    Harl::error(void) {

    std::cout << BG_RED
    << "ERROR:" << RESET
    << " A critical error has occurred; the system may be unstable."
    << std::endl;
}

void Harl::complain(std::string level) {
    
    int level_num = 0;

    if (level == "DEBUG")
        level_num = 1;
    else if (level == "INFO")
        level_num = 2;
    else if (level == "WARNING")
        level_num = 3;
    else if (level == "ERROR")
        level_num = 4;
    else
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }

    switch (level_num) {
        case 1:
            Harl::debug();
        case 2:
            Harl::info();
        case 3:
            Harl::warning();
        case 4:
            Harl::error();
            break;
        default:
            break;
    }
}