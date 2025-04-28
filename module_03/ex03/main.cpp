#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {

    ClapTrap Clap("Clap One");
    std::string Clap2 = "Clap two";

    Clap.displayStatus();

    Clap.attack(Clap2);
    Clap.takeDamage(5);
    Clap.beRepaired(1);

    Clap.displayStatus();

    Clap.attack(Clap2);
    Clap.takeDamage(6);
    Clap.beRepaired(3);

    Clap.displayStatus();

    // ================================= //

    ScavTrap scav("Robot Scav");
    std::string scav2 = "Robot Scav2";

    scav.displayStatus();

    scav.attack(scav2);
    scav.takeDamage(50);
    scav.beRepaired(10);
    scav.guardGate();

    scav.displayStatus();

    scav.attack(scav2);
    scav.takeDamage(60);
    scav.beRepaired(30);
    scav.guardGate();

    scav.displayStatus();

    // ================================= //

    FragTrap Frag("Frag One");
    std::string Frag2 = "Frag two";

    Frag.displayStatus();

    Frag.attack(Frag2);
    Frag.takeDamage(40);
    Frag.beRepaired(15);
    Frag.highFivesGuys();

    Frag.displayStatus();

    Frag.attack(Frag2);
    Frag.takeDamage(35);
    Frag.beRepaired(50);
    Frag.highFivesGuys();

    Frag.displayStatus();
    
    return (0);
}