#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {

    private:
        std::string ideas[100];

    public:
        Brain(); // constructor
        Brain(const Brain &other); // copy constructor
        Brain &operator=(const Brain &other); // copy assignment constructor
        ~Brain(); // destructor
        
        const std::string  getIdea(int index) const; // getter
        void    setIdea(int index, const std::string &other); // setter
    
};

#endif