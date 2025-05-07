#include "Character.hpp"
#include "AMateria.hpp"

// constructor
Character::Character() : name("Default") {
    std::cout << "Character: Constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

// copy constructor
Character::Character(const Character &other) {
    std::cout << "Character: Copy Constructor called" << std::endl;
    this->name = other.name;

    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

// copy assignment operator
Character& Character::operator=(const Character &other) {
    std::cout << "Character: Copy Assignment operator called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    return *this;
}

// destructor
Character::~Character() {
    std::cout << "Character: Destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
}

// constructor that takes a string
Character::Character(const std::string other) {
    std::cout << "Character: Constructor that takes a string" << std::endl;
    this->name = other;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
} 

// get character's name
std::string const& Character::getName() const {
    return this->name;
}

// to equip a Materia
void Character::equip(AMateria* m) {

    std::cout << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            std::cout << "Materia equipped in inventory" << std::endl;
            this->inventory[i] = m;
            return;
        }
    }
    std::cout << "Materia not equipped in inventory" << std::endl;
}

// to unequip a Materia
void Character::unequip(int idx) {
    
    if (idx >= 0 && idx < 4) {
        std::cout << "Materia unequipped from inventory" << std::endl;
        this->inventory[idx] = NULL;
    }
}

// to use a Materia on a target
void Character::use(int idx, ICharacter& target) {
    
    if (idx >= 0 && idx < 4 && this->inventory[idx]) {
        this->inventory[idx]->use(target);
    } else {
        std::cout << "Invalid inventory slot or empty slot." << std::endl;
    }
} 