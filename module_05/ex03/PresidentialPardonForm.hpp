#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

    private:
        std::string target;
    
    protected:
        void action() const;
    
    public:
        PresidentialPardonForm(); // constructor
        PresidentialPardonForm(const PresidentialPardonForm& other); // copy constructor
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other); // copy assignment operator
        ~PresidentialPardonForm(); // destructor

        PresidentialPardonForm(std::string target); // constructor(parameters)
};
#endif