#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
        
    public:
        Intern(); // constructor
        Intern(const Intern &other); // copy constructor
        Intern& operator=(const Intern &other); // copy assignment operator
        ~Intern(); // destructor

        AForm* makeForm(const std::string &form_name, const std::string &target);

        // Define a type for the function pointer
        // typedef creates a new name to make it easier to call this pointer
        typedef AForm* (Intern::*createAForm)(const std::string&);
    
    private:
        AForm* createShrubbery(const std::string& target);
        AForm* createRobotomy(const std::string& target);
        AForm* createPardon(const std::string& target);
};

#endif