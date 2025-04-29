#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

    ClapTrap Clap("Clap_One");
    std::string Clap2 = "Clap_Two";

    displayStatus(Clap);

    Clap.attack(Clap2);
    Clap.takeDamage(5);
    Clap.beRepaired(1);

    displayStatus(Clap);

    Clap.attack(Clap2);
    Clap.takeDamage(6);
    Clap.beRepaired(3);

    displayStatus(Clap);

    // ================================= //

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