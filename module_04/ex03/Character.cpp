#include "Character.hpp"
#include "AMateria.hpp"

// constructor
Character::Character() : name("Default") {
    std::cout << "Character: Constructor called" << std::endl;
}

// copy constructor
Character::Character(const Character &other) {
    std::cout << "Character: Copy Constructor called" << std::endl;
    this->name = other.name;

    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = nullptr;
    }
}

// copy assignment operator
Character& Character::operator=(const Character &other) {
    std::cout << "Character: Copy Assignment operator called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]) {
            delete this->inventory[i];
            this->inventory[i] = nullptr;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = nullptr;
    }
    return *this;
}

// destructor
Character::~Character() {
    std::cout << "Character: Destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]) {
            delete this->inventory[i];
            this->inventory[i] = nullptr;
        }
    }
}

// constructor that takes a string
Character::Character(const std::string other) {
    std::cout << "Character: Constructor that takes a string" << std::endl;
    this->name = other;
} 

// get character's name
std::string const& Character::getName() const {
    return this->name;
}

// to equip a Materia
void Character::equip(AMateria* m) {

    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == nullptr) {
            std::cout << "Materia equipped in inventory" << std::endl;
            this->inventory[i] = m;
            return;
        }
    }
}

// to unequip a Materia
void Character::unequip(int idx) {
    
    if (idx >= 0 && idx < 4) {
        std::cout << "Materia unequipped from inventory" << std::endl;
        this->inventory[idx] = nullptr;
    }
}

// to use a Materia on a target
void Character::use(int idx, Character& target) {
    
    if (idx >= 0 && idx < 4 && this->inventory[idx]) {
        this->inventory[idx]->use(target);
    } else {
        std::cout << "Invalid inventory slot or empty slot." << std::endl;
    }
} 