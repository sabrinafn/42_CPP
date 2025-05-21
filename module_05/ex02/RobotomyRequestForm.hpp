#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
    
    private:
        std::string target;
            
    protected:
        void action() const;
    
    public:
        RobotomyRequestForm(); // constructor
        RobotomyRequestForm(const RobotomyRequestForm &other); // copy constructor
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other); // copy assignment operator
        ~RobotomyRequestForm(); // destructor
        RobotomyRequestForm(const std::string target); // constructor takes parameters
};

#endif