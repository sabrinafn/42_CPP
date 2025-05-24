#include "Bureaucrat.hpp"

int main(void) {

    std::cout << "\tWelcome.\n\nLet's create a Bureaucrat profile.\n" << std::endl;
    
    std::string name;
    int         grade;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your grade: ";
    std::cin >> grade;

    Bureaucrat* one = NULL;
    
    try {
        one = new Bureaucrat(name, grade);
        std::cout << one << std::endl;
        
        std::cout << "Test: Incrementing Grade..." << std::endl;
        one.incrementGrade();
        std::cout << one << std::endl;
        //std::cout << "Test: Decrementing Grade..." << std::endl;
        //one.decrementGrade();
        //std::cout << one << std::endl;
    } 
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } 
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete one;
    one = NULL;

    return 0;
}