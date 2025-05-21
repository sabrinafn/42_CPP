#include "PresidentialPardonForm.hpp"

// constructor
PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 25, 5) {}

// copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
    *this = other;
}

// copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        this->target = other.target;
    }
    return *this;
}

// destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// constructor(parameters)
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

void PresidentialPardonForm::action() const {
    std::cout << "PresidentialPardonForm: Informs that " << target
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}