#include "RobotomyRequestForm.hpp"

// constructor
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45), target("empty") {}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) {
    *this = other;
}

// copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
            this->target = other.target;
    }
    return *this;
}

// destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// constructor takes parameters
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {

    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }

    static bool rand_exist = false;

    // seed the random generator
    if (!rand_exist) {
        std::srand(std::time(0));
        rand_exist = true;
    }

    // get 50% chance
    if (std::rand() % 2 == 0) {
        std::cout << "SKREEEEEEEEE!\n"
                  << target << " has been robotomized successfully."
                  << std::endl;
    }
    else {
        std::cout << "VRRRRR-ZZZZT-POP...\n"
                  << target << "'s robotomy has failed!"
                  << std::endl;
    }
}