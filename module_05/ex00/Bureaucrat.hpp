#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {

    private:
        std::string name;
        int grade;
    public:
        Bureaucrat(); // constructor
        Bureaucrat(const Bureaucrat &other); // copy constructor
        Bureaucrat &operator=(const Bureaucrat &other); // copy assignment operator
        ~Bureaucrat(); // destructor

        Bureaucrat(const std::string name, const int grade); // constructor that takes a string
        std::string     getName() const; // getter for the name
        int             getGrade() const; // getter for the grade

        void    setName(const std::string name); // setter for the name
        void    setGrade(const int grade); // setter for the grade
};

// Exception class
class GradeTooHighException : public std::exception {
    
    private:
        std::string message;
    public:
        GradeTooHighException(const std::string& msg);
        virtual const char* what() const throw();
};

// Exception class
class GradeTooLowException : public std::exception {
    
    private:
        std::string message;
    public:
        GradeTooLowException(const std::string& msg);
        virtual const char* what() const throw();
};

#endif