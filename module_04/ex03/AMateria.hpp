#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

// base class
class AMateria {

    protected:
        std::string type;
    
    public:
        AMateria(); // constructor
        AMateria(const AMateria &other); // copy constructor
        AMateria &operator=(const AMateria &other); // copy assignment operator
        virtual ~AMateria(); // destructor

        AMateria(const std::string &other); // constructor that takes a std::string

        const std::string& getType(); //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;
};

#endif