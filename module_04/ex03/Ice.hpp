#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

    public:
        Ice(); // constructor
        Ice(const Ice &other); // copy constructor
        Ice &operator=(const Ice &other); // copy assignment operator
        ~Ice(); // destructor
    
        Ice *clone() const;
        //void    use(ICharacter& other) const;
};

#endif