#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

    // ================================= //

    FragTrap Frag("Frag_One");
    std::string Frag2 = "Frag_two";

    displayStatus(Frag);

    Frag.attack(Frag2);
    Frag.takeDamage(40);
    Frag.beRepaired(15);
    Frag.highFivesGuys();

    displayStatus(Frag);

    Frag.attack(Frag2);
    Frag.takeDamage(35);
    Frag.beRepaired(50);
    Frag.highFivesGuys();

    displayStatus(Frag);

    // ================================= //
    
    DiamondTrap Diamond("Diamond_One");
    std::string Diamond2 = "Diamond_Two";

    displayStatus(Diamond);

    Diamond.attack(Diamond2);
    Diamond.takeDamage(40);
    Diamond.beRepaired(15);
    Diamond.whoAmI();
    scav.guardGate();
    Frag.highFivesGuys();

    displayStatus(Diamond);

    Diamond.attack(Diamond2);
    Diamond.takeDamage(35);
    Diamond.beRepaired(50);
    Diamond.whoAmI();
    Diamond.guardGate();
    Diamond.highFivesGuys();

    displayStatus(Diamond);
    
    return (0);
}