#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {

    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(); // constructor
        Bureaucrat(const Bureaucrat &other); // copy constructor
        Bureaucrat &operator=(const Bureaucrat &other); // copy assignment operator
        ~Bureaucrat(); // destructor

        Bureaucrat(const std::string name, const int grade); // constructor that takes a string
        
        std::string     getName() const; // getter for the name
        int             getGrade() const; // getter for the grade
        void            setGrade(const int grade); // setter for the grade

        void    incrementGrade(int grade);
        void    decrementGrade(int grade);

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other); // insertion operator

// Exception class
class GradeTooHighException : public std::exception {
    
    private:
        const char* message;
    public:
        GradeTooHighException();
        virtual const char* what() const throw();
};

// Exception class
class GradeTooLowException : public std::exception {
    
    private:
        const char* message;
    public:
        GradeTooLowException();
        virtual const char* what() const throw();
};

#endif