#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

    private:
        std::string name;

    public:
        DiamondTrap(); // constructor
        DiamondTrap(const DiamondTrap &other); // copy constructor
        DiamondTrap &operator=(const DiamondTrap &other); // copy assignment operator
        ~DiamondTrap(); // destructor

        DiamondTrap(std::string name); // constructor that takes std::string name
        void    attack(const std::string& target);
        
        void    whoAmI();

};

void    displayStatus(const DiamondTrap &Robot);

#endif