#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap {

    private:
        const std::string   name;
        int                 hit_points;
        int                 energy_points;
        int                 attack_damage; 

    public:
        ClapTrap(); // constructor
        ClapTrap(const ClapTrap &other); // copy constructor operator
        ClapTrap &operator=(const ClapTrap &other); // copy assignment operator
        ~ClapTrap(); // destructor

        ClapTrap(const std::string name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif