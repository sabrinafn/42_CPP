#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

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
        // validate data in data.csv
        bool BitcoinExchange::data_valid(std::map<std::string, float> data);
};

#endif