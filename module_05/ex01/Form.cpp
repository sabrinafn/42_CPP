#include "Form.hpp"

    // private:
    //     const std::string   name;
    //     bool                is_signed;
    //     const int           grade_required_to_sign;
    //     const int           grade_required_to_execute;
// constructor
Form::Form()
    : name("empty"), 
      is_signed(false),
      grade_required_to_sign(-1),
      grade_required_to_execute(-1) {
    std::cout << "Form: Constructor called" << std::endl;
}

// copy constructor
Form::Form(const Form &other) {
    std::cout << "Form: Copy construtor called" << std::endl;
    *this = other;
}

// copy assignment operator
Form& Form::operator=(const Form &other) {
    std::cout << "Form: Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
} 

// destructor
Form::~Form() {
    std::cout << "Form: Destructor called" << std::endl;
}

// constructor takes parameters
Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : name(name), 
    is_signed(false), // always starts as false
    grade_required_to_sign(gradeToSign),
    grade_required_to_execute(gradeToExecute) {

    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
        std::cout << "Form: Constructor(parameters) called" << std::endl;
}

// GETTERS

const std::string   Form::getName() {
    return this->name;
}

bool    Form::getIsSigned() {
    return this->is_signed;
}

const int   Form::getGradeRequiredToSign() {
    return this->grade_required_to_sign;
}

const int   Form::getGradeRequiredToExecute() {
    return this->grade_required_to_execute;
}


// changes form's status if bureaucrat's grade is high enough
void    Form::beSigned(const Bureaucrat &guy) {
    
}

        // attempt to sign the form
        void    signForm(const Form &paper);

        // exception classes
        class GradeTooHighException : public std::exception {
            private:
                const char* message;
            public:
                GradeTooHighException();
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            private:
                const char* message;
            public:
                GradeTooLowException();
                virtual const char* what() const throw();
        };
};

// insertion operator
std::ostream &operator<<(std::ostream &out, const Form &other);