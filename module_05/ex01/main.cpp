#include "Bureaucrat.hpp"

int main(void) {

    std::cout << "\tWelcome.\n\nLet's create a new Bureaucrat profile.\n" << std::endl;
    std::string name;
    int grade;

    while (true) {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);

        std::cout << "Enter your grade: ";
        std::cin >> grade;

        try {
            Bureaucrat one = Bureaucrat(name, grade);
            std::cout << one << std::endl;
            
            std::cout << "Test: Incrementing Grade..." << std::endl;
            std::cout << one << std::endl;
            one.incrementGrade();
            std::cout << one << std::endl;

            //std::cout << "Test: Decrementing Grade..." << std::endl;
            //std::cout << one << std::endl;
            //one.decrementGrade();
            //std::cout << one << std::endl;
        } 
        catch (const GradeTooHighException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } 
        catch (const GradeTooLowException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "Press enter to continue or exit to quit." << std::endl;
        std::cin.ignore();
        std::getline(std::cin, name);
        if (name == "exit")
            break ;
    }
    return 0;
}