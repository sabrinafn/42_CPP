#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {

    private:
    	static const int	MAX_GRADE = 1; // static means that it does not belong to a object
		static const int	MIN_GRADE = 150; // but to the whole class
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

        void    incrementGrade();
        void    decrementGrade();

        // Exception class for grades that are too high
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        // Exception class for grades that are too low
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other); // insertion operator

#endif