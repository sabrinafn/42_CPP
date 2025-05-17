#include "Bureaucrat.hpp"

// constructor
Bureaucrat::Bureaucrat() : name("empty"), grade(-1) {
   //std::cout << "Bureaucrat: Constructor called" << std::endl;
} 

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    //std::cout << "Bureaucrat: Copy constructor called" << std::endl;
    *this = other;
}

// copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    //std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

// destructor
Bureaucrat::~Bureaucrat() {
    //std::cout << "Bureaucrat: Destructor called" << std::endl;
}

// constructor that takes args
Bureaucrat::Bureaucrat(const std::string name, const int grade) : name(name) {

    if (grade < MIN_GRADE)
        throw GradeTooHighException();
    else if (grade > MAX_GRADE)
        throw GradeTooLowException();
    else
        this->grade = grade;
    //std::cout << "Bureaucrat: Constructor with parameters" << std::endl;
}

// getter for the name
std::string Bureaucrat::getName() const {
    return this->name;
}

// getter for the grade
int   Bureaucrat::getGrade() const {
    return grade;
}

// function to increment grade
void    Bureaucrat::incrementGrade() {
    if (grade <= MIN_GRADE)
        throw GradeTooHighException();
    else
        grade--; 
}

// function to decrement grade
void    Bureaucrat::decrementGrade() {
    
    if (grade >= MAX_GRADE)
        throw GradeTooLowException();
    else
        grade++;
}

// insertion operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &other) {

    out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";;
    return out;
}

// Grade TOO HIGH exception
GradeTooHighException::GradeTooHighException() {
    message = "Grade too high!";
}

const char* GradeTooHighException::what() const throw() {
    return message;
}

// Grade TOO LOW exception
GradeTooLowException::GradeTooLowException() {
        message = "Grade too low!";
}

const char* GradeTooLowException::what() const throw() {
    return message;
}