#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main() {
    
    std::cout << "=============================================================" << std::endl;
    std::cout << "|                     Testing HumanA                        |" << std::endl;
    std::cout << "=============================================================" << std::endl;

    // HumanA's name
    std::string nameA = "Finn";

    // creating a Weapon object
    Weapon weaponA("Shiny Sword");

    std::cout << "Creating HumanA " << nameA << " with weapon: " << weaponA.getType() << std::endl;

    // Creating HumanA with nameA and reference to weapon
    HumanA warriorA(nameA, weaponA);
    warriorA.attack();

    // Modify the Weapon object that WarriorA is referencing
    weaponA.setType("Extra Shiny Sword");
    std::cout << "Weapon changed to: " << weaponA.getType() << std::endl;
    warriorA.attack();

    std::cout << std::endl;


    std::cout << "=============================================================" << std::endl;
    std::cout << "|                     Testing HumanB                        |" << std::endl;
    std::cout << "=============================================================" << std::endl;
    
    // HumanA's name
    std::string nameB = "Jake";

    // Creating HumanB without a weapon
    HumanB warriorB(nameB);
    warriorB.attack();

    // Creating a Weapon
    Weapon weaponB("Sharp Sword");
    std::cout << "Creating Weapon: " << weaponB.getType() << std::endl;

    // Equip HumanB with the weapon
    warriorB.setWeapon(weaponB);
    std::cout << "Equipping " << nameB << " with: " << weaponB.getType() << std::endl;
    warriorB.attack();

    // Modify the Weapon object that ScoutB is pointing to
    weaponB.setType("Extra Sharp Sword");
    std::cout << "Weapon changed to: " << weaponB.getType() << std::endl;
    warriorB.attack();

    return 0;
}

/*int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}*/
