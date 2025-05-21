#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    
    try {
        Bureaucrat bob = Bureaucrat("Bob", 100);
        std::cout << bob << std::endl;
        ShrubberyCreationForm tree("home");
        tree.beSigned(bob);      // bob must have grade <= 145
        tree.execute(bob);       // bob must have grade <= 137
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
