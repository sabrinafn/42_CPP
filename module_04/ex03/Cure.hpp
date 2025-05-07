#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {

    public:
        Cure(); // constructor
        Cure(const Cure &other); // copy constructor
        Cure &operator=(const Cure &other); // copy assignment operator
        ~Cure(); // destructor

        Cure *clone() const;
        //void    use(ICharacter& other) const;
};

#endif