#include "ScavTrap.hpp"

int main(void) {

    ScavTrap scav("Scav_One");
    std::string scav2 = "Scav_Two";

    displayStatus(scav);

    scav.attack(scav2);
    scav.takeDamage(50);
    scav.beRepaired(10);
    scav.guardGate();

    displayStatus(scav);

    scav.attack(scav2);
    scav.takeDamage(60);
    scav.beRepaired(30);
    scav.guardGate();

    displayStatus(scav);

    return (0);
}