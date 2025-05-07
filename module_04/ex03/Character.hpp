#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
    
    private:
        std::string name;
        AMateria* inventory[4];

    public:
        Character(); // constructor
        Character(const Character &other); // copy constructor
        Character &operator=(const Character &other); // copy assignment operator
        ~Character() {}; // destructor

        Character(const std::string other); // constructor that takes a string

        std::string const & getName() const; // get character's name
        void equip(AMateria* m); // to equip a Materia
        void unequip(int idx); // to unequip a Materia
        void use(int idx, Character& target); // to use a Materia on a target

};

#endif