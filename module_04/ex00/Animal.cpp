#include "Animal.hpp"

// constructor
Animal::Animal() : type("default") {
    std::cout << "Animal: Default constructor called" << std::endl;
}

// copy constructor
Animal::Animal(const Animal &other) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = other;
}

// copy assignment constructor
Animal& Animal::operator=(const Animal &other) {
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// destructor
Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
}

// constructor that takes a string as parameter
Animal::Animal(std::string other) {
    std::cout << "Animal: Constructor that takes a string as parameter" << std::endl;
    this->type = other;
}

// getter
Animal::Animal  getType() const {

}
void    setType(Animal &other); // setter

void    makeSound(); // output the animal sound 