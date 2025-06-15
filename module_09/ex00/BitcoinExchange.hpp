#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {

    private:
        std::map<std::string, float> container;
    
    public:
        
        /* CONSTRUCTORS */
        BitcoinExchange(void);
        BitcoinExchange(std::map<std::string, float> &data);
        BitcoinExchange(const BitcoinExchange &other);

        /* DESTRUCTORS */
        ~BitcoinExchange(void);

        /* OPERATORS */
        BitcoinExchange& operator=(const BitcoinExchange &other);

        /* METHODS */
        void runBitcoinExchange(std::ifstream file);

};

bool is_date_valid(std::string date);
bool is_value_valid(std::string value);

#endif