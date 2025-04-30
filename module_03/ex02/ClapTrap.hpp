#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

#define RESET       "\033[0m"
#define GREEN       "\033[32m"
#define BLUE        "\033[34m"

class   ClapTrap {

    protected:
        std::string   name;
        int           hit_points;
        int           energy_points;
        int           attack_damage;

    public:
        ClapTrap(); // constructor
        ClapTrap(const ClapTrap &other); // copy constructor operator
        ClapTrap &operator=(const ClapTrap &other); // copy assignment operator
        ~ClapTrap(); // destructor

        ClapTrap(const std::string name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
        // getter functions
        std::string getName() const;
        int         getHitPoints() const;
        int         getEnergyPoints() const;
        int         getAttackDamage() const;

        // setter functions
        void    setName(const std::string other);
        void    setHitPoints(const int other);
        void    setEnergyPoints(const int other);
        void    setAttackDamage(const int other);
};

void    displayStatus(const ClapTrap &robot);


/*
Hit Points: Represents the health of the ClapTrap;Initialized to 10; reduced when attacked; can be increased.
Energy Points: Represents ability to act (attack/repair); Initialized to 10; cannot be increased.
Attack Damage: Represents how much damage is dealt to enemies; initialized to 0.
- ClapTrap can’t do anything if it has no hit points or energy points left.
*/

#endif