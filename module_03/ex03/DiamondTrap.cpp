#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name("unnamed") {

    std::cout << "DiamondTrap Constructor called" << std::endl;
    hit_points = FragTrap::hit_points; // FragTrap hit points
    energy_points = ScavTrap::energy_points; // ScavTrap energy points
    attack_damage = FragTrap::attack_damage; // FragTrap attack damage
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {

    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {

    std::cout << "DiamondTrap Copy Assignment operator called" << std::endl;
    if (this != &other) {

        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {

    std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {

    this->name = name; // DiamondTrap name
    hit_points = FragTrap::hit_points; // FragTrap hit points
    energy_points = ScavTrap::energy_points; // ScavTrap energy points
    attack_damage = FragTrap::attack_damage; // FragTrap attack damage
}

void    DiamondTrap::attack(const std::string& target) {

    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI() {

    std::cout << "whoAmI: DiamondTrap's name is " << DiamondTrap::name
    << " and its ClapTrap's name is " << ClapTrap::name
    << std::endl;
}

std::string DiamondTrap::getName() const {
    return this->name; // DiamondTrap's name
}

void    displayStatus(const DiamondTrap &Robot) {

    std::cout << MAGENTA << "\n= DiamondTrap Status ====================" << RESET << std::endl;

    std::cout << MAGENTA << "| " << RESET << RED << std::setw(15) << std::left 
              << "Name: " << Robot.getName() << RESET << std::endl;

    std::cout << MAGENTA << "| " << RESET << RED << std::setw(15) << std::left
              << "Hit Points: " << Robot.getHitPoints() << RESET << std::endl;
    
    std::cout << MAGENTA << "| " << RESET << RED << std::setw(15) << std::left
              << "Energy Points: " << Robot.getEnergyPoints() << RESET << std::endl;

    std::cout << MAGENTA << "| " << RESET << RED << std::setw(15) << std::left
              << "Attack Damage: " << Robot.getAttackDamage() << RESET << std::endl;

    std::cout << MAGENTA << "=========================================" << RESET << "\n" << std::endl;
}