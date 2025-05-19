#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form {

    private:
        const std::string   name;
        bool                is_signed;
        const int           grade_required_to_sign;
        const int           grade_required_to_execute;

    public:
        // exception classes

        class GradeTooHighException : public std::exception {
            private:
                const char* message;
            
            public:
                GradeTooHighException();
                virtual const char* what() const throw();
        }

        class GradeTooLowException :

}

#endif