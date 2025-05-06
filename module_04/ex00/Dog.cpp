#include "Dog.hpp"

// constructor
Dog::Dog() : Animal("Dog") {
    std::cout << "Dog: Default constructor called" << std::endl;
}

// copy constructor
Dog::Dog(const Dog &other) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    *this = other;
}

// copy assignment constructor
Dog& Dog::operator=(const Dog &other) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// destructor
Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
}

// constructor that takes a string as parameter
Dog::Dog(std::string other) {
    std::cout << "Dog: Constructor that takes a string as parameter" << std::endl;
    this->type = other;
}

// getter
const std::string Dog::getType() const {
    return this->type;
}

// setter
void    Dog::setType(const Dog &other) {
    this->type = other.type;
} 

// output the Dog sound
void    Dog::makeSound() const {
    std::cout << "WOOF" << std::endl;
}