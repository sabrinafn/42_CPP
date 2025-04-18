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

void    Harl::complain(std::string level) {

    // Array of function pointers
    complaintFunctionPtr complaints[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // Array of level strings
    static const std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    int i;
    for (i = 0; i < 4; i++) {
        if (levels[i] == level) {
            // calling the function at pos i in the array
            (this->*complaints[i])();
            return ;
        }
    }
    if (i == 4) {
        std::cout << "Invalid Level" << std::endl;
    }
}