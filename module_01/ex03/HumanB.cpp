#include "HumanB.hpp"

HumanB::HumanB(const std::string& humanName) : name(humanName), weapon(NULL) {
    //std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB() {
    //std::cout << "HumanB destructor called" << std::endl;
}

void    HumanB::setWeapon(Weapon& newWeapon) {
    this->weapon = &newWeapon;
}

void    HumanB::attack() const {
    if (this->weapon == NULL)
        std::cout << this->name << " can't attack without a weapon." << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;    
}