#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    
    std::cout << "===== Testing ShrubberyCreationForm =====\n" << std::endl;
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        Bureaucrat bob = Bureaucrat("Bob", 100);
        std::cout << bob << std::endl;
        Intern guy;
        AForm* tree = guy.makeForm("ShrubberyCreationForm", "tree");
        if (tree) {
            std::cout << *tree << std::endl;
            tree->beSigned(bob);      // bob must have grade <= 145
            bob.executeForm(*tree);   // bob must have grade <= 137
            delete (tree);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Testing RobotomyRequestForm =====\n" << std::endl;
    
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        Bureaucrat john = Bureaucrat("John", 40);
        std::cout << john << std::endl;
        Intern guy;
        AForm* robotomy = guy.makeForm("RobotomyRequestForm", "robotomy");
        if (robotomy) {
            std::cout << *robotomy << std::endl;
            robotomy->beSigned(john);      // john must have grade <= 72
            john.executeForm(*robotomy);   // john must have grade <= 45
            delete (robotomy);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Testing PresidentialPardonForm =====\n" << std::endl;
    
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        Bureaucrat anna = Bureaucrat("Anna", 3);
        std::cout << anna << std::endl;
        Intern guy;
        AForm* pardon = guy.makeForm("PresidentialPardonForm", "pardon");
        if (pardon) {
            std::cout << *pardon << std::endl;
            pardon->beSigned(anna);      // anna must have grade <= 25
            anna.executeForm(*pardon);   // anna must have grade <= 5
            delete (pardon);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

        std::cout << "\n===== Testing wrong form =====\n" << std::endl;
    
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        Bureaucrat anna = Bureaucrat("Anna", 3);
        std::cout << anna << std::endl;
        Intern guy;
        AForm* pardon = guy.makeForm("wrong form", "pardon");
        if (pardon) {
            std::cout << *pardon << std::endl;
            pardon->beSigned(anna);      // anna must have grade <= 25
            anna.executeForm(*pardon);       // anna must have grade <= 5
            delete (pardon);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
