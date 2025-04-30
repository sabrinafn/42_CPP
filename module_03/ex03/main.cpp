#include "DiamondTrap.hpp"

int main(void) {

    DiamondTrap Diamond("Diamond_One");
    std::string Diamond2 = "Diamond_Two";

    displayStatus(Diamond);

    Diamond.attack(Diamond2);
    Diamond.takeDamage(40);
    Diamond.beRepaired(15);

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