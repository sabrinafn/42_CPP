#include "Dog.hpp"

// constructor
Dog::Dog() : Animal("Dog") {
    brain = new Brain();
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
    delete brain;
    std::cout << "Dog: Destructor called" << std::endl;
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