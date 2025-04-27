#include "ClapTrap.hpp"

// =============== Orthodox Canonical Form =============== //

ClapTrap::ClapTrap() : name("unnamed"), hit_points(10), energy_points(10), attack_damage(0) {

    std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    
    std::cout << "Copy Constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {

    std::cout << "Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage; 
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    
    std::cout << "Destructor called" << std::endl;
}

// ======================================================== //

ClapTrap::ClapTrap(const std::string name) :  name(name), hit_points(10), energy_points(10), attack_damage(0) {

    std::cout << "Constructor called (const std::string)" << std::endl;
}

void ClapTrap::attack(const std::string& target) {

    if (this->energy_points == 0) {
        std::cout << "Attack: ClapTrap " << this->name << " does not have energy points to attack "
                  << target << "." <<std::endl;
        return;
    }

    std::cout << "Attack: ClapTrap " << this->name << " attacks " << target 
    << ", causing " << attack_damage << " points of damage!" << std::endl; 

    this->energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {

    if ((int)amount >= hit_points) { // if attack power can kill the ClapTrap
        std::cout << "takeDamage: ClapTrap " << name
                  << " has taken all the damage it can take and is now dead!" << std::endl;
        hit_points = 0;
    } else if ((int)amount < hit_points) { // if attack power causes damage, but cannot kill the ClapTrap 
        std::cout << "takeDamage: ClapTrap " << this->name << " takes "
                  << amount << " points of damage!" << std::endl;
    
        this->hit_points -= amount;
    } else { // if ClapTrap is already dead, so cannot receive damage
        std::cout << "takeDamage: ClapTrap " << name
                  << " is already dead and cannot take any more damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {

    if (this->energy_points > 0) {
        
        std::cout << "beRepaired: ClapTrap " << this->name << " repairs itself. " << amount 
        << " points repaired." << std::endl;
        
        this->hit_points += amount;
        this->energy_points -= 1;
    } else {
        std::cout << "beRepaired: ClapTrap " << this->name
                  << " doesn't have enough energy points to repair!" << std::endl;
    }
}

void ClapTrap::displayStatus() const
{

    std::cout << GREEN << "\n= ClapTrap Status =================" << RESET << std::endl;

    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left 
              << "Name: " << name << RESET << std::endl;

    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left
              << "Hit Points: " << hit_points << RESET << std::endl;
    
    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left
              << "Energy Points: " << energy_points << RESET << std::endl;

    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left
              << "Attack Damage: " << attack_damage << RESET << std::endl;

    std::cout << GREEN << "===================================" << RESET << "\n" << std::endl;
}
