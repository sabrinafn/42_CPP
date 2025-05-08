#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
    public:
        virtual ~ICharacter() {}; // destructor
        virtual std::string const & getName() const = 0; // get character's name
        virtual void equip(AMateria* m) = 0; // to equip a Materia
        virtual void unequip(int idx) = 0; // to unequip a Materia
        virtual void use(int idx, ICharacter& target) = 0; // to use a Materia on a target
};

#endif