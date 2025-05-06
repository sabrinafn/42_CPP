#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {

    public:
        Dog(); // constructor
        Dog(const Dog &other); // copy constructor
        Dog &operator=(const Dog &other); // copy assignment constructor
        ~Dog(); // destructor
        Dog(std::string other); // constructor that takes a string as parameter
        
        const std::string  getType() const; // getter
        void    setType(const Dog &other); // setter
        void    makeSound() const; // output the Dog sound 

};

#endif