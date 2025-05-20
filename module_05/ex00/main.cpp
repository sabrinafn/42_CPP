#include "Bureaucrat.hpp"
#include <cstdlib>

// Helper function to check if a string is numeric
bool isNumeric(const std::string& str) {
    
    if (str.empty())
        return false;

    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

// nao funciona com numeros negativos


int main(void) {

    std::cout << "\tWelcome.\n\nLet's create a new Bureaucrat profile.\n" << std::endl;
    
    std::string name;
    std::string grade_str;
    int         grade;

    while (true) {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);

        std::cout << "Enter your grade: ";
        std::getline(std::cin, grade_str);

        if (!isNumeric(grade_str)) {
            std::cerr << "Invalid grade: grade must be a number." << std::endl;
            continue;
        }
        grade = std::atoi(grade_str.c_str());

        try {
            Bureaucrat one = Bureaucrat(name, grade);
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

        std::cout << "Press enter to continue or type 'exit' to quit." << std::endl;
        std::cin.ignore();
        std::getline(std::cin, name);
        if (name == "exit")
            break ;
    }
    return 0;
}