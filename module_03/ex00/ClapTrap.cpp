#include "ClapTrap.hpp"

// =============== Orthodox Canonical Form =============== //

ClapTrap::ClapTrap() {

    std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    
    std::cout << "Copy Constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {

    std::cout << "copy assignment operator called" << std::endl;
    if (this != &other)

}

ClapTrap(); // destructor

ClapTrap(const std::string name);
void attack(const std::string& target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);