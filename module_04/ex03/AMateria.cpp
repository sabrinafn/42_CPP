#include "AMateria.hpp"

// constructor
AMateria::AMateria() : type("default") {
    std::cout << "AMateria: Constructor called" << std::endl;
}

// copy constructor
AMateria::AMateria(const AMateria &other) {
    std::cout << "AMateria: Copy Constructor called" << std::endl;
    this->type = other.type;
}

// copy assignment operator
AMateria& AMateria::operator=(const AMateria &other) {
    std::cout << "AMateria: Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// destructor
AMateria::~AMateria() {
    std::cout << "AMateria: Destructor called" << std::endl;
}

// constructor that takes a std::string
AMateria::AMateria(const std::string &other) : type(other) {
    std::cout << "AMateria: Constructor that takes a std::string called" << std::endl;
}

//Returns the materia type
const std::string& AMateria::getType() {
    return this->type;
}

void    use(ICharacter &other) {
}