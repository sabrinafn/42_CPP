#include "Dog.hpp"

// constructor
Dog::Dog() : Animal("Dog") {
    brain = new Brain();
    std::cout << "Dog: Default constructor called" << std::endl;
}

// copy constructor
Dog::Dog(const Dog &other) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    this->type = other.type;
    this->brain = new Brain(*other.brain);
}

// copy assignment constructor
Dog& Dog::operator=(const Dog &other) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &other) {
        delete this->brain;
        this->type = other.type;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

// destructor
Dog::~Dog() {
    delete this->brain;
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

void Dog::setBrainIdea(int index, const std::string &idea) {
	if (this->brain)
		this->brain->setIdea(index, idea);
}

const std::string  Dog::getIdea(int index) const {
    return brain->getIdea(index);
}