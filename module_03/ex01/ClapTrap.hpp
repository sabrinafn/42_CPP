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
        int                 hit_points; //represents life; reduces when attacked; can be increased.
        int                 energy_points; // represents ability to act (attack and repair); cannot be increased.
        int                 attack_damage; //

    public:
        ClapTrap(); // constructor
        ClapTrap(const ClapTrap &other); // copy constructor operator
        ClapTrap &operator=(const ClapTrap &other); // copy assignment operator
        ~ClapTrap(); // destructor

        ClapTrap(const std::string name);
        virtual void attack(const std::string& target);
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

#endif