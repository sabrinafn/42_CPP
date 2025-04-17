#include "Weapon.hpp"

Weapon::Weapon(const std::string& weaponType) : type(weaponType){
    //std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon() {
    //std::cout << "Weapon destructor called" << std::endl;
}

const std::string& Weapon::getType() const{
    return this->type;
}

void    Weapon::setType(const std::string& newType) {
    this->type = newType;
}