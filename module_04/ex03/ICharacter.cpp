#include "ICharacter.hpp"

// constructor
ICharacter::ICharacter() {
    std::cout << "ICharacter: Constructor called" << std::endl;
}

// copy constructor
ICharacter::ICharacter(const ICharacter &other) {
    std::cout << "ICharacter: Copy Constructor called" << std::endl;
    *this = other;
}

// copy assignment operator
ICharacter& ICharacter::operator=(const ICharacter &other) {
    std::cout << "ICharacter: Copy Assignment operator called" << std::endl;
    if (this != &other) {
        *this = other;
    }
    return *this;
}