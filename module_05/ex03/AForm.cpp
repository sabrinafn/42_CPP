#include "AForm.hpp"
#include "Bureaucrat.hpp"

// constructor
AForm::AForm()
    : name("empty"), 
      is_signed(false),
      grade_required_to_sign(-1),
      grade_required_to_execute(-1) {

    if (grade_required_to_sign < MAX_GRADE || grade_required_to_execute < MAX_GRADE)
        throw GradeTooHighException();
    if (grade_required_to_sign > MIN_GRADE || grade_required_to_execute > MIN_GRADE)
        throw GradeTooLowException();
    //std::cout << "AForm: Constructor called" << std::endl;
}

// copy constructor
AForm::AForm(const AForm &other)
    : name(other.name),
      is_signed(other.is_signed),
      grade_required_to_sign(other.grade_required_to_sign),
      grade_required_to_execute(other.grade_required_to_execute) {
    //std::cout << "AForm: Copy construtor called" << std::endl;
}

// copy assignment operator
AForm& AForm::operator=(const AForm &other) {
    //std::cout << "AForm: Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
} 

// destructor
AForm::~AForm() {
    //std::cout << "AForm: Destructor called" << std::endl;
}

// constructor takes parameters
AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
    : name(name), 
    is_signed(false), // always starts as false
    grade_required_to_sign(gradeToSign),
    grade_required_to_execute(gradeToExecute) {

    //std::cout << "AForm: Constructor(parameters) called" << std::endl;
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE) {
        throw GradeTooHighException();
    }
    if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE) {
        throw GradeTooLowException();
    }
}
// GETTERS

std::string   AForm::getName() const {
    return this->name;
}

bool    AForm::getIsSigned() const {
    return this->is_signed;
}

int   AForm::getGradeRequiredToSign() const {
    return this->grade_required_to_sign;
}

int   AForm::getGradeRequiredToExecute() const {
    return this->grade_required_to_execute;
}


// changes AForm's status if bureaucrat's grade is high enough
void    AForm::beSigned(const Bureaucrat &guy) {

    // check if bureaucrat's grade is high enough to sign the AForm
    if (guy.getGrade() > this->grade_required_to_sign) {
        throw AForm::GradeTooLowException();
    }
    this->is_signed = true;
}

// exception classes

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: Grade too low!";       
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm: Form not signed!";
}

// insertion operator
std::ostream &operator<<(std::ostream &out, const AForm &paper) {

    if (paper.getIsSigned()) {
        out << paper.getName() << ", Form is signed, requires grade " 
            << paper.getGradeRequiredToSign() << " to sign, " << paper.getGradeRequiredToExecute()
            << " to execute.";
    }
    else {
        out << paper.getName() << ", Form is unsigned, requires grade " 
            << paper.getGradeRequiredToSign() << " to sign, " << paper.getGradeRequiredToExecute()
            << " to execute.";
    }
    return out;
}

void    AForm::execute(Bureaucrat const& executor) const {
    
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }
    this->action();
}