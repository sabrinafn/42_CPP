#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {

    private:
        const std::string   name;
        bool                is_signed;
        const int           grade_required_to_sign;
        const int           grade_required_to_execute;

    public:
        Form(); // constructor
        Form(const Form &other); // copy constructor
        Form &operator=(const Form &other); // copy assignment operator
        ~Form(); // destructor
        Form(const std::string name, int gradeToSign, int gradeToExecute); // constructor takes parameters

        // GETTERS

        const std::string   getName();
        bool                getIsSigned();
        const int           getGradeRequiredToSign();
        const int           getGradeRequiredToExecute();

        // changes form's status if bureaucrat's grade is high enough
        void    beSigned(const Bureaucrat &guy);

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

#endif