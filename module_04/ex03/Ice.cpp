#include "Ice.hpp"
#include "AMateria.hpp"

// constructor
Ice::Ice() : AMateria("Ice") {
    std::cout << "Ice: Constructor called" << std::endl;
}

// copy constructor
Ice::Ice(const Ice &other) {
    std::cout << "Ice: Copy Constructor called" << std::endl;
    this->type = other.type;
}

// copy assignment operator
Ice Ice&::operator=(const Ice &other) {

} 

~Ice(); // destructor

Ice *clone() const;
//void    use(ICharacter& other) const;
