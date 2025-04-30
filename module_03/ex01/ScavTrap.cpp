#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {

    std::cout << "ScavTrap Default Constructor called" << std::endl;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
    
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {

    std::cout << "ScavTrap Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage; 
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap Constructor called (const std::string)" << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

void ScavTrap::attack(const std::string& target) {

    if (this->energy_points <= 0) {
        std::cout << "Attack: ScavTrap " << this->name << " does not have energy points to attack "
                  << target << "." <<std::endl;
    } else if (this->hit_points <= 0) {
        std::cout << "Attack: ScavTrap " << this->name << " does not have hit points to attack "
                  << target << "." <<std::endl;
    } else {
        std::cout << "Attack: ScavTrap " << this->name << " attacks " << target 
        << ", causing " << attack_damage << " points of damage!" << std::endl; 
        this->energy_points -= 1;
    }
}

void    ScavTrap::guardGate() {

    std::cout << "guardGate: " << this->name << " is now in Gate Keeper mode!" << std::endl;
}

// =============================================== //

void    displayStatus(const ScavTrap &robot) {

    std::cout << YELLOW << "\n= ScavTrap Status =================" << RESET << std::endl;

    std::cout << YELLOW << "| " << RESET << RED << std::setw(15) << std::left 
              << "Name: " << robot.getName() << RESET << std::endl;

    std::cout << YELLOW << "| " << RESET << RED << std::setw(15) << std::left
              << "Hit Points: " << robot.getHitPoints() << RESET << std::endl;
    
    std::cout << YELLOW << "| " << RESET << RED << std::setw(15) << std::left
              << "Energy Points: " << robot.getEnergyPoints() << RESET << std::endl;

    std::cout << YELLOW << "| " << RESET << RED << std::setw(15) << std::left
              << "Attack Damage: " << robot.getAttackDamage() << RESET << std::endl;

    std::cout << YELLOW << "===================================" << RESET << "\n" << std::endl;
}