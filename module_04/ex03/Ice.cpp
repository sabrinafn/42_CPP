#include "Ice.hpp"
#include "AMateria.hpp"

// constructor
Ice::Ice() : AMateria("Ice") {
    std::cout << "Ice: Constructor called" << std::endl;
}

// copy constructor
Ice::Ice(const Ice &other) {
    std::cout << "Ice: Copy Constructor called" << std::endl;
    *this = other;
}

// copy assignment operator
Ice& Ice::operator=(const Ice &other) {
    std::cout << "Ice: Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
} 

// destructor
Ice::~Ice() {
    std::cout << "Ice: Desctructor called" << std::endl;
}

Ice*    Ice::clone() const {
    return new Ice(*this);
}

//void    Ice::use(ICharacter& other) const {
//    std::cout << "* shoots an ice bolt at " << other << " *" << std::endl;
//}
