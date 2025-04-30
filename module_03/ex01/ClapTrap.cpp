#include "ClapTrap.hpp"

// =============== Orthodox Canonical Form =============== //

ClapTrap::ClapTrap() : name("unnamed"), hit_points(10), energy_points(10), attack_damage(0) {

    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {

    std::cout << "ClapTrap Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage; 
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    
    std::cout << "ClapTrap Destructor called" << std::endl;
}

// ======================================================== //

ClapTrap::ClapTrap(const std::string name) :  name(name), hit_points(10), energy_points(10), attack_damage(0) {

    std::cout << "ClapTrap Constructor called (const std::string)" << std::endl;
}

void ClapTrap::attack(const std::string& target) {

    if (this->energy_points <= 0) {
        std::cout << "Attack: ClapTrap " << this->name << " does not have energy points to attack "
                  << target << "." <<std::endl;
    } else if (this->hit_points <= 0) {
        std::cout << "Attack: ClapTrap " << this->name << " does not have hit points to attack "
                  << target << "." <<std::endl;
    } else {
        std::cout << "Attack: ClapTrap " << this->name << " attacks " << target 
        << ", causing " << attack_damage << " points of damage!" << std::endl; 
        this->energy_points -= 1;
    }
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

    if (this->hit_points <= 0) {
        std::cout << "beRepaired: ClapTrap " << this->name
                  << " doesn't have enough hit points!" << std::endl;
    } else if (this->energy_points > 0) {
        std::cout << "beRepaired: ClapTrap " << this->name << " repairs itself. " << amount 
        << " points repaired." << std::endl;
        
        this->hit_points += amount;
        this->energy_points -= 1;
    } else {
        std::cout << "beRepaired: ClapTrap " << this->name
                  << " doesn't have enough energy points to repair!" << std::endl;
    }
}

// GETTER FUNCTIONS

std::string ClapTrap::getName() const {
    return this->name;
}

int ClapTrap::getHitPoints() const {
    return this->hit_points;
}

int ClapTrap::getEnergyPoints() const {
    return this->energy_points;
}

int ClapTrap::getAttackDamage() const {
    return this->attack_damage;
}

// SETTER FUNCTIONS

void ClapTrap::setName(const std::string other) {
    this->name = other;
}

void ClapTrap::setHitPoints(const int other) {
    this->hit_points = other;
}

void ClapTrap::setEnergyPoints(const int other) {
    this->energy_points = other;
}

void ClapTrap::setAttackDamage(const int other) {
    this->attack_damage = other;
}

// =============================================== //

void displayStatus(const ClapTrap &robot) {

    std::cout << GREEN << "\n= ClapTrap Status =================" << RESET << std::endl;

    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left 
              << "Name: " << robot.getName() << RESET << std::endl;

    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left
              << "Hit Points: " << robot.getHitPoints() << RESET << std::endl;
    
    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left
              << "Energy Points: " << robot.getEnergyPoints() << RESET << std::endl;

    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left
              << "Attack Damage: " << robot.getAttackDamage() << RESET << std::endl;

    std::cout << GREEN << "===================================" << RESET << "\n" << std::endl;
}