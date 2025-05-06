#include "Brain.hpp"

// constructor
Brain::Brain() {
    std::cout << "Brain: Constructor called." << std::endl;
}

// copy constructor
Brain::Brain(const Brain &other) {
    std::cout << "Brain: Copy Constructor called." << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

// copy assignment constructor
Brain& Brain::operator=(const Brain &other) {
    std::cout << "Brain: Copy assignment operator called." << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
    }
    return *this;
}

// destructor
Brain::~Brain() {
    std::cout << "Brain: Destructor was called" << std::endl;
}

// getter
const std::string  Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}

// setter
void    Brain::setIdea(int index, const std::string &other) {
    if (index >= 0 && index < 100)
        this->ideas[index] = other;
}
