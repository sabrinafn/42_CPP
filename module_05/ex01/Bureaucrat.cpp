#include "Bureaucrat.hpp"
#include "Form.hpp"

// constructor
Bureaucrat::Bureaucrat() : name("empty"), grade(-1) {
   //std::cout << "Bureaucrat: Constructor called" << std::endl;
} 

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
    //std::cout << "Bureaucrat: Copy constructor called" << std::endl;
}

// copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    //std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

// destructor
Bureaucrat::~Bureaucrat() {
    //std::cout << "Bureaucrat: Destructor called" << std::endl;
}

// constructor that takes args
Bureaucrat::Bureaucrat(const std::string name, const int grade) : name(name) {

    if (grade < MAX_GRADE)
        throw GradeTooHighException();
    if (grade > MIN_GRADE)
        throw GradeTooLowException();
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
    if (grade <= MAX_GRADE)
        throw GradeTooHighException();
    grade--; 
}

// function to decrement grade
void    Bureaucrat::decrementGrade() {
    
    if (grade >= MIN_GRADE)
        throw GradeTooLowException();
    grade++;
}

// insertion operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &other) {

    out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";;
    return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat: Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat: Grade too low!";
}

// attempt to sign the form
void    Bureaucrat::signForm(Form &paper) {
    try {
        paper.beSigned(*this);
        std::cout << name << " signed " << paper.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << paper.getName() 
                  << " because " << e.what() << std::endl;
    }
}