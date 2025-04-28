#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class FragTrap : public ClapTrap {

    public:
        FragTrap(); // constructor
        FragTrap(const FragTrap &other); // copy constructor
        FragTrap &operator=(const FragTrap &other); // copy assignment constructor
        ~FragTrap(); // destructor

        FragTrap(const std::string name); // constructor that takes a string
        void    attack(const std::string& target);
        void highFivesGuys(void);

        void displayStatus() const;

};

#endif