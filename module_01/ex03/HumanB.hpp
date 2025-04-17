#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {

    private:
        std::string name;
        Weapon* weapon; // pointer to a weapon
        // HumanB not always will have a weapon, so it can point to null
        // it points to a weapon object that exist elsewhere

    public:
        HumanB(const std::string& humanName);
        ~HumanB();
        void setWeapon(Weapon& newWeapon);
        void attack() const;
};

#endif