#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

// base class
class AMateria {

    protected:
        std::string type;
    
    public:
        AMateria(); // constructor
        AMateria(const AMateria &other); // copy constructor
        AMateria &operator=(const AMateria &other); // copy assignment operator
        ~AMateria(); // destructor

        AMateria(const std::string &other); // constructor that takes a std::string
        virtual AMateria* clone() const = 0;
        //virtual void use(ICharacter& target);
};

#endif