#include "Bureaucrat.hpp"

int main(void) {

    std::cout << "\tWelcome.\n\nLet's create a new Bureaucrat profile.\n" << std::endl;
    std::string name;
    int grade;

    while (true) {
        std::cin.ignore();
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);

        std::cout << "Enter your grade: ";
        std::cin >> grade;

        try {
            Bureaucrat one = Bureaucrat(name, grade);
            std::cout << one << std::endl;
        } 
        catch (const GradeTooHighException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } 
        catch (const GradeTooLowException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } 
        catch (const std::exception& e) { // generic exception if other errors are encountered
            std::cerr << "Unexpected exception: " << e.what() << std::endl;
        }
        std::cout << "Press enter to continue or exit to quit." << std::endl;
        std::cin.ignore();
        std::getline(std::cin, name);
        if (name == "exit")
            break ;
    }
    return 0;
}