#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

// base class
class Animal {

    protected:
        std::string type;
        Animal(); // constructor

    public:
        Animal(const Animal &other); // copy constructor
        Animal &operator=(const Animal &other); // copy assignment constructor
        virtual ~Animal(); // destructor

        Animal(std::string other); // constructor that takes a string as parameter
        
        const std::string  getType() const; // getter
        void    setType(const Animal &other); // setter

        virtual void    makeSound() const; // output the animal sound 
};

#endif