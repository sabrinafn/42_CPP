#ifndef AAForm_HPP
#define AAForm_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {

    private:
        const std::string   name;
        bool                is_signed;
        const int           grade_required_to_sign;
        const int           grade_required_to_execute;
        static const int	MAX_GRADE = 1; // static means that it does not belong to a object
		static const int	MIN_GRADE = 150; // but to the whole class

    protected:
        virtual void action() const = 0;

    public:
        AForm(); // constructor
        AForm(const AForm &other); // copy constructor
        AForm &operator=(const AForm &other); // copy assignment operator
        virtual ~AForm(); // destructor
        AForm(const std::string name, int gradeToSign, int gradeToExecute); // constructor takes parameters

        // GETTERS

        std::string   getName() const;
        bool          getIsSigned() const;
        int           getGradeRequiredToSign() const;
        int           getGradeRequiredToExecute() const;

        // changes AForm's status if bureaucrat's grade is high enough
        void    beSigned(const Bureaucrat &guy);

        // attempt to sign the AForm
        void    signForm(const AForm &paper);

        // exception classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    
        virtual void execute(Bureaucrat const& executor) const;

};

// insertion operator
std::ostream &operator<<(std::ostream &out, const AForm &paper);

#endif