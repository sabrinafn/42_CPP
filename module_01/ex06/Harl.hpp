#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {

    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

    public:
        void    complain(std::string level);
        // Define a type for the function pointer
        // typedef creates a new name to make it easier to call this pointer
        typedef void (Harl::*complaintFunctionPtr)(void);
};

#define RESET "\033[0m"

#define BG_WHITE "\033[47m"
#define BLACK "\033[30m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_RED "\033[41m"

#endif