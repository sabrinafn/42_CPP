#include "ClapTrap.hpp"

int main(void) {

    ClapTrap robot("Robot_One");
    std::string robot2 = "Robot_Two";

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