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

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 250)
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
    return this->grade;
}

// setter for the grade
void    Bureaucrat::setGrade(const int grade) {
    this->grade = grade;
}

// function to increment grade
void    incrementGrade(int grade) {
    if (grade <= 1)
        throw GradeTooHighException();
    else
        grade--; 
}

// function to decrement grade
void    decrementGrade(int grade) {
    
    if (grade >= 150)
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
        message = "Grade too high!";
}

const char* GradeTooLowException::what() const throw() {
    return message;
}