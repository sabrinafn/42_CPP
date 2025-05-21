#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
        Bureaucrat bob = Bureaucrat("Second Bob", 138);
        std::cout << bob << std::endl;
        ShrubberyCreationForm tree("second tree");
        std::cout << tree << std::endl;
        tree.beSigned(bob);      // bob must have grade <= 145
        tree.execute(bob);       // bob must have grade <= 137
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Testing RobotomyRequestForm =====\n" << std::endl;
    
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        Bureaucrat john = Bureaucrat("John", 40);
        std::cout << john << std::endl;
        RobotomyRequestForm robotomy("this robot guy");
        std::cout << robotomy << std::endl;
        robotomy.beSigned(john);      // john must have grade <= 72
        robotomy.execute(john);       // john must have grade <= 45
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

        try {
        std::cout << "\n=== Creating another bureaucrat...\n" << std::endl;
        Bureaucrat john = Bureaucrat("Second John", 100);
        std::cout << john << std::endl;
        RobotomyRequestForm robotomy("another robot guy");
        std::cout << robotomy << std::endl;
        robotomy.beSigned(john);      // john must have grade <= 72
        robotomy.execute(john);       // john must have grade <= 45
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Testing PresidentialPardonForm =====\n" << std::endl;
    
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        Bureaucrat anna = Bureaucrat("Anna", 3);
        std::cout << anna << std::endl;
        PresidentialPardonForm pardon("this guy");
        std::cout << pardon << std::endl;
        pardon.beSigned(anna);      // anna must have grade <= 25
        pardon.execute(anna);       // anna must have grade <= 5
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Creating another bureaucrat...\n" << std::endl;
        Bureaucrat anna = Bureaucrat("Second Anna", 10);
        std::cout << anna << std::endl;
        PresidentialPardonForm pardon("another guy");
        std::cout << pardon << std::endl;
        pardon.beSigned(anna);      // anna must have grade <= 25
        pardon.execute(anna);       // anna must have grade <= 5
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
