#include "AForm.hpp"
#include "Intern.hpp"

// constructor
Intern::Intern() {}

// copy constructor
Intern::Intern(const Intern &other) {
    (void)other;
}

// copy assignment operator
Intern& Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

// destructor
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &form_name, const std::string &target) {

    // Array of function pointers
    createAForm options[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPardon
    };

    // Array of forms strings
    static const std::string form_types[3] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    };

    for (int i = 0; i < 3; i++) {
    if (form_types[i] == form_name) {
            // calling the function at pos i in the array
            std::cout << "Intern creates " << form_name << std::endl;
            return(this->*options[i])(target);
        }
    }
    std::cout << "Intern cannot create form: "  << form_name
                  << " is not a valid form" << std::endl;
    return NULL;
}

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}
