#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {

    protected:
        std::string type;

    public:
        Animal(); // constructor
        Animal(const Animal &other); // copy constructor
        Animal &operator=(const Animal &other); // copy assignment constructor
        ~Animal(); // destructor

        Animal(std::string other); // constructor that takes a string as parameter
        
        Animal  getType() const; // getter
        void    setType(Animal &other); // setter

        void    makeSound(); // output the animal sound 
};

#endif