#include "Character.hpp"

// constructor
Character::Character() {
    std::cout << "Character: Constructor called" << std::endl;
}

// copy constructor
Character::Character(const Character &other) {
    std::cout << "Character: Copy Constructor called" << std::endl;
    *this = other;
}

// copy assignment operator
Character& Character::operator=(const Character &other) {

}

// destructor
Character::~Character() {
    std::cout << "Character: Destructor called" << std::endl;
}

Character(const std::string other); // constructor that takes a string

std::string const & getName() const; // get character's name
void equip(AMateria* m); // to equip a Materia
void unequip(int idx); // to unequip a Materia
void use(int idx, Character& target); // to use a Materia on a target