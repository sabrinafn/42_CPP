#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {

    public:
        Intern(); // constructor
        Intern(const Intern &other); // copy constructor
        Intern& operator=(const Intern &other); // copy assignment operator
        ~Intern(); // destructor

        AForm* makeForm(const std::string &form_name, const std::string &target);
};

#endif