#include "AForm.hpp"
#include "Intern.hpp"

// constructor
Intern::Intern() {}

// copy constructor
Intern::Intern(const Intern &other) {}

// copy assignment operator
Intern& Intern::operator=(const Intern &other) {}

// destructor
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &form_name, const std::string &target) {

    std::cout << "Intern creates " << form_name << std::endl;

    std::cout << "Intern cannot create form: "  << form_name
              << " is not a valid form" << std::endl;


}
