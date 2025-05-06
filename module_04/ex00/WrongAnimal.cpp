#include "WrongAnimal.hpp"

// constructor
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

// copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    *this = other;
}

// copy assignment constructor
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// destructor
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

// constructor that takes a string as parameter
WrongAnimal::WrongAnimal(std::string other) {
    std::cout << "WrongAnimal: Constructor that takes a string as parameter" << std::endl;
    this->type = other;
}

// getter
const std::string WrongAnimal::getType() const {
    return this->type;
}

// setter
void    WrongAnimal::setType(const WrongAnimal &other) {
    this->type = other.type;
} 

// output the WrongAnimal sound
void    WrongAnimal::makeSound() const {
    std::cout << "abcdef" << std::endl;
}