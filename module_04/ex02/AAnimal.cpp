#include "AAnimal.hpp"

// constructor
AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal: Default constructor called" << std::endl;
}

// copy constructor
AAnimal::AAnimal(const AAnimal &other) {
    std::cout << "AAnimal: Copy constructor called" << std::endl;
    *this = other;
}

// copy assignment constructor
AAnimal& AAnimal::operator=(const AAnimal &other) {
    std::cout << "AAnimal: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// destructor
AAnimal::~AAnimal() {
    std::cout << "AAnimal: Destructor called" << std::endl;
}

// constructor that takes a string as parameter
AAnimal::AAnimal(std::string other) {
    std::cout << "AAnimal: Constructor that takes a string as parameter" << std::endl;
    this->type = other;
}

// getter
const std::string AAnimal::getType() const {
    return this->type;
}

// setter
void    AAnimal::setType(const AAnimal &other) {
    this->type = other.type;
} 

// output the AAnimal sound
void    AAnimal::makeSound() const {
    std::cout << "abcdef" << std::endl;
}