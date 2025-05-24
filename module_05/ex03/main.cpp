#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    
    std::cout << "===== Testing ShrubberyCreationForm =====\n" << std::endl;
    std::cout << "=== Creating bureaucrat...\n" << std::endl;
    Bureaucrat* bob = NULL;
    Intern* guy = NULL;
    AForm* tree = NULL;
    try {
        bob = new Bureaucrat("Bob", 150);
        std::cout << *bob << std::endl;
        guy = new Intern();
        tree = guy->makeForm("ShrubberyCreationForm", "tree");
        if (tree) {
            std::cout << *tree << std::endl;
            tree->beSigned(*bob);      // bob must have grade <= 145
            bob->executeForm(*tree);   // bob must have grade <= 137
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete bob;
    delete guy;
    delete tree;
    bob = NULL;
    guy = NULL;
    tree = NULL;


    std::cout << "\n===== Testing RobotomyRequestForm =====\n" << std::endl;
    
    Bureaucrat* john = NULL;
    AForm* robotomy = NULL;
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        john = new Bureaucrat("John", 40);
        std::cout << *john << std::endl;
        guy = new Intern();
        robotomy = guy->makeForm("RobotomyRequestForm", "robotomy");
        if (robotomy) {
            std::cout << *robotomy << std::endl;
            robotomy->beSigned(*john);      // john must have grade <= 72
            john->executeForm(*robotomy);   // john must have grade <= 45
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete john;
    delete guy;
    delete robotomy;
    john = NULL;
    guy = NULL;
    robotomy = NULL;


    std::cout << "\n===== Testing PresidentialPardonForm =====\n" << std::endl;
    
    Bureaucrat* anna = NULL;
    AForm* pardon = NULL;
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        anna = new Bureaucrat("Anna", 3);
        std::cout << *anna << std::endl;
        guy = new Intern();
        pardon = guy->makeForm("PresidentialPardonForm", "pardon");
        if (pardon) {
            std::cout << *pardon << std::endl;
            pardon->beSigned(*anna);      // anna must have grade <= 25
            anna->executeForm(*pardon);   // anna must have grade <= 5
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete anna;
    delete guy;
    delete pardon;
    anna = NULL;
    guy = NULL;
    pardon = NULL;

    std::cout << "\n===== Testing wrong form =====\n" << std::endl;
    
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        anna = new Bureaucrat("Anna", 3);
        std::cout << *anna << std::endl;
        guy = new Intern();
        pardon = guy->makeForm("wrong form", "pardon");
        if (pardon) {
            std::cout << *pardon << std::endl;
            pardon->beSigned(*anna);      // anna must have grade <= 25
            anna->executeForm(*pardon);       // anna must have grade <= 5
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete anna;
    delete guy;
    delete pardon;
    anna = NULL;
    guy = NULL;
    pardon = NULL;

    return 0;
}
