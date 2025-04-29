#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {

    std::cout << "FragTrap Default Constructor called" << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) {
    
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {

    std::cout << "FragTrap Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage; 
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap Constructor called (const std::string)" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

void FragTrap::highFivesGuys(void) {

    std::cout << "highFivesGuys: " << this->name << " asks for a high five!" << std::endl;
}

// =============================================== //

void displayStatus(const FragTrap &robot) {

    std::cout << CYAN << "\n= FragTrap Status =================" << RESET << std::endl;

    std::cout << CYAN << "| " << RESET << MAGENTA << std::setw(15) << std::left 
              << "Name: " << robot.getName() << RESET << std::endl;

    std::cout << CYAN << "| " << RESET << MAGENTA << std::setw(15) << std::left
              << "Hit Points: " << robot.getHitPoints() << RESET << std::endl;
    
    std::cout << CYAN << "| " << RESET << MAGENTA << std::setw(15) << std::left
              << "Energy Points: " << robot.getEnergyPoints() << RESET << std::endl;

    std::cout << CYAN << "| " << RESET << MAGENTA << std::setw(15) << std::left
              << "Attack Damage: " << robot.getAttackDamage() << RESET << std::endl;

    std::cout << CYAN << "===================================" << RESET << "\n" << std::endl;
}
