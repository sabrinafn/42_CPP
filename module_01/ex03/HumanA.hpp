#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {

    private:
        std::string name;
        Weapon& weapon; // reference to a weapon
        // 1. HumanA will always be armed, so it will be created with one
        // 2. HumanA receives a Weapon object that was created outside of it#
        // this HumanA does not own the weapon, it's only linked to it

    public:
        HumanA(const std::string& humanName, Weapon& humanWeapon);
        ~HumanA();
        void attack() const;

};

#endif