#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
    public:
        IMateriaSource(); // constructor
        IMateriaSource(const IMateriaSource &other); // copy constructor
        IMateriaSource &operator=(const IMateriaSource &other); // copy assignment operator
        virtual ~IMateriaSource() {}; // destructor

        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif