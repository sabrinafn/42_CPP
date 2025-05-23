#include "Form.hpp"
#include "Bureaucrat.hpp"

// constructor
Form::Form()
    : name("empty"), 
      is_signed(false),
      grade_required_to_sign(-1),
      grade_required_to_execute(-1) {

    if (grade_required_to_sign < MAX_GRADE || grade_required_to_execute < MAX_GRADE)
        throw GradeTooHighException();
    if (grade_required_to_sign > MIN_GRADE || grade_required_to_execute > MIN_GRADE)
        throw GradeTooLowException();
    //std::cout << "Form: Constructor called" << std::endl;
}

// copy constructor
Form::Form(const Form &other)
    : name(other.name),
      is_signed(other.is_signed),
      grade_required_to_sign(other.grade_required_to_sign),
      grade_required_to_execute(other.grade_required_to_execute) {
    //std::cout << "Form: Copy construtor called" << std::endl;
}

// copy assignment operator
Form& Form::operator=(const Form &other) {
    //std::cout << "Form: Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
} 

// destructor
Form::~Form() {
    //std::cout << "Form: Destructor called" << std::endl;
}

// constructor takes parameters
Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : name(name), 
    is_signed(false), // always starts as false
    grade_required_to_sign(gradeToSign),
    grade_required_to_execute(gradeToExecute) {

    //std::cout << "Form: Constructor(parameters) called" << std::endl;
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE) {
        throw GradeTooHighException();
    }
    if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE) {
        throw GradeTooLowException();
    }
}
// GETTERS

std::string   Form::getName() const {
    return this->name;
}

bool    Form::getIsSigned() const {
    return this->is_signed;
}

int   Form::getGradeRequiredToSign() const {
    return this->grade_required_to_sign;
}

int   Form::getGradeRequiredToExecute() const {
    return this->grade_required_to_execute;
}


// changes form's status if bureaucrat's grade is high enough
void    Form::beSigned(const Bureaucrat &guy) {

    // check if bureaucrat's grade is high enough to sign the form
    if (guy.getGrade() > this->grade_required_to_sign) {
        throw Form::GradeTooLowException();
    }
    this->is_signed = true;
}

// exception classes

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade too low!";       
}

// insertion operator
std::ostream &operator<<(std::ostream &out, const Form &paper) {

    if (paper.getIsSigned()) {
        out << paper.getName() << ", form is signed, requires grade " 
            << paper.getGradeRequiredToSign() << " to sign, " << paper.getGradeRequiredToExecute()
            << " to execute.";
    }
    else {
        out << paper.getName() << ", form is unsigned, requires grade " 
            << paper.getGradeRequiredToSign() << " to sign, " << paper.getGradeRequiredToExecute()
            << " to execute.";
    }
    return out;
}