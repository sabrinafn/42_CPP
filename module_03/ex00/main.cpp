#include "ClapTrap.hpp"

void displayStatus(ClapTrap robot) {

    std::cout << GREEN << "\n= ClapTrap Status =================" << RESET << std::endl;

    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left 
              << "Name: " << robot.getName() << RESET << std::endl;

    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left
              << "Hit Points: " << robot.getHitPoints() << RESET << std::endl;
    
    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left
              << "Energy Points: " << robot.getEnergyPoints() << RESET << std::endl;

    std::cout << GREEN << "| " << RESET << BLUE << std::setw(15) << std::left
              << "Attack Damage: " << robot.getAttackDamage() << RESET << std::endl;

    std::cout << GREEN << "===================================" << RESET << "\n" << std::endl;
}

int main(void) {

    ClapTrap robot("Robot One");
    std::string robot2 = "Robot two";

    displayStatus(robot);

    robot.attack(robot2);
    robot.takeDamage(5);
    robot.beRepaired(1);

    displayStatus(robot);

    robot.attack(robot2);
    robot.takeDamage(6);
    robot.beRepaired(3);

    displayStatus(robot);

    return (0);
}