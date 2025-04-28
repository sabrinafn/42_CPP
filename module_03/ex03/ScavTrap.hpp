#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

#define RED "\033[31m"
#define YELLOW "\033[33m"

class ScavTrap : virtual public ClapTrap {

    public:
        ScavTrap(); // constructor
        ScavTrap(const ScavTrap &other); // copy constructor
        ScavTrap &operator=(const ScavTrap &other); // copy assignment operator
        ~ScavTrap(); // destructor

        ScavTrap(std::string name); // constructor that takes std::string
        void    attack(const std::string& target);

        void    guardGate(); // defense mode
        void    displayStatus() const;
};

#endif