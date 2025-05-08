#include "MateriaSource.hpp"

// constructor
MateriaSource::MateriaSource() {
    //std::cout << "MateriaSource: Constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        storage[i] = NULL;
    }
}

// copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) {
    //std::cout << "MateriaSource: Copy Constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.storage[i])
            storage[i] = other.storage[i]->clone();
        else
            storage[i] = NULL;
    }
}

// copy assignment operator
MateriaSource& MateriaSource::operator=(const MateriaSource &other) {
    //std::cout << "MateriaSource: Copy Assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete storage[i];
            if (other.storage[i])
                storage[i] = other.storage[i]->clone();
            else
                storage[i] = NULL;
        }
    }
    return *this;
}

// destructor
MateriaSource::~MateriaSource() {
    //std::cout << "MateriaSource: Destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete storage[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;

    for (int i = 0; i < 4; i++) {
        if (storage[i] == NULL) {
            storage[i] = m->clone();
            std::cout << "MateriaSource: Learned " << m->getType() << std::endl;
            return;
        }
    }

    std::cout << "MateriaSource: Storage is full, cannot learn more Materia" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string &type) {

    for (int i = 0; i < 4; i++) {
        if (storage[i] && storage[i]->getType() == type) {
            std::cout << "MateriaSource: Creating " << type << std::endl;
            return storage[i]->clone();
        }
    }
    std::cout << "MateriaSource: Materia " << type << " not found" << std::endl;
    return NULL;
}