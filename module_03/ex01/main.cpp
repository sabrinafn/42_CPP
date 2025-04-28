#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

    ClapTrap robot("Robot One");
    std::string robot2 = "Robot two";

    robot.displayStatus();

    robot.attack(robot2);
    robot.takeDamage(5);
    robot.beRepaired(1);

    robot.displayStatus();

    robot.attack(robot2);
    robot.takeDamage(6);
    robot.beRepaired(3);

    robot.displayStatus();

    return (0);
}