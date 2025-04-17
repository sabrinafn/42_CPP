#include "HumanA.hpp"

HumanA::HumanA(const std::string& humanName, Weapon& humanWeapon) : name(humanName), weapon(humanWeapon){
    //std::cout << "HumanA constructor called" << std::endl;
}

HumanA::~HumanA() {
    //std::cout << "HumanA destructor called" << std::endl;
}

void    HumanA::attack() const{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}