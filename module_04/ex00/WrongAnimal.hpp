#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

// base class
class WrongAnimal {

    protected:
        std::string type;

    public:
        WrongAnimal(); // constructor
        WrongAnimal(const WrongAnimal &other); // copy constructor
        WrongAnimal &operator=(const WrongAnimal &other); // copy assignment constructor
        ~WrongAnimal(); // destructor

        WrongAnimal(std::string other); // constructor that takes a string as parameter
        
        const std::string  getType() const; // getter
        void    setType(const WrongAnimal &other); // setter

        void    makeSound() const; // output the WrongAnimal sound 
};

#endif