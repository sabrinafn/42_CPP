#include "Cat.hpp"

// constructor
Cat::Cat() : Animal("Cat"){
    brain = new Brain();
    std::cout << "Cat: Default constructor called" << std::endl;
}

// copy constructor
Cat::Cat(const Cat &other) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    this->type = other.type;
    this->brain = new Brain(*other.brain);
}

// copy assignment constructor
Cat& Cat::operator=(const Cat &other) {
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    if (this != &other) {
        delete this->brain;
        this->type = other.type;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

// destructor
Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat: Destructor called" << std::endl;
}

// getter
const std::string Cat::getType() const {
    return this->type;
}

// setter
void    Cat::setType(const Cat &other) {
    this->type = other.type;
} 

// output the Cat sound
void    Cat::makeSound() const {
    std::cout << "MEOW" << std::endl;
}

void Cat::setBrainIdea(int index, const std::string &idea) {
	if (this->brain)
		this->brain->setIdea(index, idea);
}

const std::string  Cat::getIdea(int index) const {
    return brain->getIdea(index);
}