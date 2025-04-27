#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

class   ClapTrap {

    private:
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
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void displayStatus() const;
};


#endif