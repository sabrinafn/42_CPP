#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class MyMap {

    private:
        std::map<std::string, double> container;
    
    public:
        
        /* CONSTRUCTORS */
        MyMap(void);
        MyMap(const MyMap &other);

        /* DESTRUCTORS */
        ~MyMap(void);

        /* OPERATORS */
        MyMap& operator=(const MyMap &other);

        /* METHODS */
        
};

#endif