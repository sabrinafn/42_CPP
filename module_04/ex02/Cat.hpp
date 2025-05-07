#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

    private:
        Brain* brain;

    public:
        Cat(); // constructor
        Cat(const Cat &other); // copy constructor
        Cat &operator=(const Cat &other); // copy assignment constructor
        ~Cat(); // destructor
        Cat(std::string other); // constructor that takes a string as parameter
        
        const std::string  getType() const; // getter
        void    setType(const Cat &other); // setter
        void    makeSound() const; // output the Cat sound
        void    setBrainIdea(int index, const std::string &idea);
        const std::string  getIdea(int index) const;
        
};

#endif