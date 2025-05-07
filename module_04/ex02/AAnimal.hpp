#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

// base class
class AAnimal {

    protected:
        std::string type;
        AAnimal(); // constructor

    public:
        AAnimal(const AAnimal &other); // copy constructor
        AAnimal &operator=(const AAnimal &other); // copy assignment constructor
        virtual ~AAnimal(); // destructor

        AAnimal(std::string other); // constructor that takes a string as parameter
        
        const std::string  getType() const; // getter
        void    setType(const AAnimal &other); // setter

        virtual void    makeSound() const; // output the AAnimal sound 
};

#endif