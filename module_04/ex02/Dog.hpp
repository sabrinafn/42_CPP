#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

    private:
        Brain* brain;

    public:
        Dog(); // constructor
        Dog(const Dog &other); // copy constructor
        Dog &operator=(const Dog &other); // copy assignment constructor
        ~Dog(); // destructor
        Dog(std::string other); // constructor that takes a string as parameter
        
        const std::string  getType() const; // getter
        void    setType(const Dog &other); // setter
        void    makeSound() const; // output the Dog sound 
        void    setBrainIdea(int index, const std::string &idea);
        const std::string  getIdea(int index) const;
        
};

#endif