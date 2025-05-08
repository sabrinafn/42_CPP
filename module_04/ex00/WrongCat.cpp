#include "WrongCat.hpp"

// constructor
WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

// copy constructor
WrongCat::WrongCat(const WrongCat &other) {
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    *this = other;
}

// copy assignment constructor
WrongCat& WrongCat::operator=(const WrongCat &other) {
    std::cout << "WrongCat: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// destructor
WrongCat::~WrongCat() {
    std::cout << "WrongCat: Destructor called" << std::endl;
}

// constructor that takes a string as parameter
WrongCat::WrongCat(std::string other) {
    std::cout << "WrongCat: Constructor that takes a string as parameter" << std::endl;
    this->type = other;
}

// getter
const std::string WrongCat::getType() const {
    return this->type;
}

// setter
void    WrongCat::setType(const WrongCat &other) {
    this->type = other.type;
} 

// output the WrongCat sound
void    WrongCat::makeSound() const {
    std::cout << "MEOWMEOW" << std::endl;
}