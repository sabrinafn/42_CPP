#include "Cure.hpp"

// constructor
Cure::Cure() : AMateria("Cure") {
    std::cout << "Cure: Constructor called" << std::endl;
}

// copy constructor
Cure::Cure(const Cure &other) {
    std::cout << "Cure: Copy Constructor called" << std::endl;
    *this = other;
}

// copy assignment operator
Cure& Cure::operator=(const Cure &other) {
    std::cout << "Cure: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// destructor
Cure::~Cure() {
    std::cout << "Cure: Destructor called" << std::endl;
}

Cure* Cure::clone() const{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& other){
    std::cout << "* heals " << other.getName() << "'s wounds *" << std::endl;
}