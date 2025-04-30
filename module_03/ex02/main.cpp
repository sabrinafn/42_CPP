#include "FragTrap.hpp"

int main(void) {

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
    
    return (0);
}