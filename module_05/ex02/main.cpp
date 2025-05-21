#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    
    std::cout << "===== Testing ShrubberyCreationForm =====\n" << std::endl;
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        Bureaucrat bob = Bureaucrat("Bob", 100);
        std::cout << bob << std::endl;
        ShrubberyCreationForm tree("tree");
        std::cout << tree << std::endl;
        tree.beSigned(bob);      // bob must have grade <= 145
        tree.execute(bob);       // bob must have grade <= 137
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Creating another bureaucrat...\n" << std::endl;
        Bureaucrat bob2 = Bureaucrat("Second Bob", 138);
        std::cout << bob2 << std::endl;
        ShrubberyCreationForm tree2("second tree");
        std::cout << tree2 << std::endl;
        tree2.beSigned(bob2);      // bob2 must have grade <= 145
        tree2.execute(bob2);       // bob2 must have grade <= 137
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Testing RobotomyRequestForm =====\n" << std::endl;
    
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        Bureaucrat john = Bureaucrat("John", 40);
        std::cout << john << std::endl;
        RobotomyRequestForm robotomy("this_robot_guy");
        std::cout << robotomy << std::endl;
        robotomy.beSigned(john);      // john must have grade <= 72
        robotomy.execute(john);       // john must have grade <= 45
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

        try {
        std::cout << "\n=== Creating bureaucrat...\n" << std::endl;
        Bureaucrat john2 = Bureaucrat("Second John", 100);
        std::cout << john2 << std::endl;
        RobotomyRequestForm robotomy("this_robot_guy");
        std::cout << robotomy << std::endl;
        robotomy.beSigned(john2);      // john2 must have grade <= 72
        robotomy.execute(john2);       // john2 must have grade <= 45
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
