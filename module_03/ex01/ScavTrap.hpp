#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {

    private:

    public:
        ScavTrap(); // constructor
        ScavTrap(const ScavTrap &other); // copy constructor
        ScavTrap &operator=(const ScavTrap &other); // copy assignment operator
        ~ScavTrap(); // destructor

        void    guardGate();
};

#endif