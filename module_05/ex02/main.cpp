#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    
    std::cout << "===== Testing ShrubberyCreationForm =====\n" << std::endl;
    std::cout << "=== Creating bureaucrat...\n" << std::endl;
    Bureaucrat bob = Bureaucrat("Bob", 100);
    std::cout << bob << std::endl;
    AForm *form = new ShrubberyCreationForm("tree");
    try {
        std::cout << *form << std::endl;
        form->beSigned(bob);      // bob must have grade <= 145
        bob.executeForm(*form);       // bob must have grade <= 137
        std::cout << *form << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete (form);

    /***********************************************************************/

    Bureaucrat bob2 = Bureaucrat("Second Bob", 138);
    std::cout << bob2 << std::endl;
    AForm *form2 = new ShrubberyCreationForm("second tree");
    try {
        std::cout << "\n=== Creating another bureaucrat...\n" << std::endl;
        std::cout << *form2 << std::endl;
        form2->beSigned(bob2);      // bob must have grade <= 145
        bob2.executeForm(*form2);       // bob must have grade <= 137
        std::cout << *form2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete (form2);

    /***********************************************************************/

    std::cout << "\n===== Testing RobotomyRequestForm =====\n" << std::endl;

    std::cout << "=== Creating bureaucrat...\n" << std::endl;
    Bureaucrat john = Bureaucrat("John", 40);
    std::cout << john << std::endl;
    AForm *form3 = new RobotomyRequestForm("this robot guy");
    try {
        std::cout << *form3 << std::endl;
        form3->beSigned(john);      // john must have grade <= 72
        john.executeForm(*form3);   // john must have grade <= 45
        std::cout << *form3 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete (form3);

    /***********************************************************************/

    std::cout << "\n=== Creating another bureaucrat...\n" << std::endl;
    Bureaucrat john2 = Bureaucrat("Second John", 100);
    std::cout << john2 << std::endl;
    AForm *form4 = new RobotomyRequestForm("another robot guy");
    try {
        std::cout << *form4 << std::endl;
        form4->beSigned(john2);      // john must have grade <= 72
        john2.executeForm(*form4);       // john must have grade <= 45
        std::cout << *form4 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete (form4);

    /***********************************************************************/

    std::cout << "\n===== Testing PresidentialPardonForm =====\n" << std::endl;
   
    std::cout << "=== Creating bureaucrat...\n" << std::endl;
    Bureaucrat anna = Bureaucrat("Anna", 3);
    std::cout << anna << std::endl;
    AForm *form5 = new PresidentialPardonForm("this guy");
    try {
        std::cout << *form5 << std::endl;
        form5->beSigned(anna);      // anna must have grade <= 25
        anna.executeForm(*form5);       // anna must have grade <= 5
        std::cout << *form5 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete (form5);

    /***********************************************************************/

    std::cout << "\n=== Creating another bureaucrat...\n" << std::endl;
    Bureaucrat anna2 = Bureaucrat("Second Anna", 10);
    std::cout << anna2 << std::endl;
    AForm *form6 = new PresidentialPardonForm("another guy");
    try {
        std::cout << *form6 << std::endl;
        form6->beSigned(anna2);      // anna must have grade <= 25
        anna2.executeForm(*form6);       // anna must have grade <= 5
        std::cout << *form6 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete (form6);
    
    return 0;
}
