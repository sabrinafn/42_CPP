#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat* bureaucrat = NULL;
    AForm* form = NULL;

    std::cout << "===== Testing ShrubberyCreationForm =====\n" << std::endl;
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        bureaucrat = new Bureaucrat("Bob", 100);
        std::cout << *bureaucrat << std::endl;

        form = new ShrubberyCreationForm("tree");
        std::cout << *form << std::endl;

        form->beSigned(*bureaucrat);
        bureaucrat->executeForm(*form);
        std::cout << *form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete form;
    delete bureaucrat;

    /***********************************************************************/

    bureaucrat = NULL;
    form = NULL;
    try {
        std::cout << "\n=== Creating another bureaucrat...\n" << std::endl;
        bureaucrat = new Bureaucrat("Second Bob", 138);
        std::cout << *bureaucrat << std::endl;

        form = new ShrubberyCreationForm("second tree");
        std::cout << *form << std::endl;

        form->beSigned(*bureaucrat);
        bureaucrat->executeForm(*form);
        std::cout << *form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete form;
    delete bureaucrat;

    /***********************************************************************/

    bureaucrat = NULL;
    form = NULL;
    std::cout << "\n===== Testing RobotomyRequestForm =====\n" << std::endl;
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        bureaucrat = new Bureaucrat("John", 40);
        std::cout << *bureaucrat << std::endl;

        form = new RobotomyRequestForm("this robot guy");
        std::cout << *form << std::endl;

        form->beSigned(*bureaucrat);
        bureaucrat->executeForm(*form);
        std::cout << *form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete form;
    delete bureaucrat;

    /***********************************************************************/

    bureaucrat = NULL;
    form = NULL;
    try {
        std::cout << "\n=== Creating another bureaucrat...\n" << std::endl;
        bureaucrat = new Bureaucrat("Second John", 100);
        std::cout << *bureaucrat << std::endl;

        form = new RobotomyRequestForm("another robot guy");
        std::cout << *form << std::endl;

        form->beSigned(*bureaucrat);
        bureaucrat->executeForm(*form);
        std::cout << *form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete form;
    delete bureaucrat;

    /***********************************************************************/

    bureaucrat = NULL;
    form = NULL;
    std::cout << "\n===== Testing PresidentialPardonForm =====\n" << std::endl;
    try {
        std::cout << "=== Creating bureaucrat...\n" << std::endl;
        bureaucrat = new Bureaucrat("Anna", 3);
        std::cout << *bureaucrat << std::endl;

        form = new PresidentialPardonForm("this guy");
        std::cout << *form << std::endl;

        form->beSigned(*bureaucrat);
        bureaucrat->executeForm(*form);
        std::cout << *form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete form;
    delete bureaucrat;

    /***********************************************************************/

    bureaucrat = NULL;
    form = NULL;
    try {
        std::cout << "\n=== Creating another bureaucrat...\n" << std::endl;
        bureaucrat = new Bureaucrat("Second Anna", 10);
        std::cout << *bureaucrat << std::endl;

        form = new PresidentialPardonForm("another guy");
        std::cout << *form << std::endl;

        form->beSigned(*bureaucrat);
        bureaucrat->executeForm(*form);
        std::cout << *form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete form;
    delete bureaucrat;

    return 0;
}
