#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:
        WrongCat(); // constructor
        WrongCat(const WrongCat &other); // copy constructor
        WrongCat &operator=(const WrongCat &other); // copy assignment constructor
        ~WrongCat(); // destructor
        WrongCat(std::string other); // constructor that takes a string as parameter
        
        const std::string  getType() const; // getter
        void    setType(const WrongCat &other); // setter
        void    makeSound() const; // output the WrongCat sound 

};

#endif