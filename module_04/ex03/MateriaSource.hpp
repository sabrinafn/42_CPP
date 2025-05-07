#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

    private:
        AMateria* storage[4];

    public:
        MateriaSource(); // constructor
        MateriaSource(const MateriaSource &other); // copy constructor
        MateriaSource &operator=(const MateriaSource &other); // copy assignment operator
        ~MateriaSource(); // destructor

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif