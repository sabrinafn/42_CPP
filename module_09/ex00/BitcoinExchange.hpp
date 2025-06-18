#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "colors.hpp"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange {

    private:
        /* CONTAINER */
        std::map<std::string, float> container;

        /* PRIVATE METHODS */
        float                           findExchangeRate(std::string &date) const;
        std::map<std::string, float>    parseDataFile(std::string &arg) const;
        bool                            isDateValid(std::string &date) const;
        bool                            isValueValid(std::string &value, bool check_limits) const;
        int                             getFebruaryDays(int &year) const;
        float                           strToFloat(std::string &str) const;
        void                            printBadInputMessage(const std::string &msg, const std::string &error) const;
    
    public:
        
        /* CONSTRUCTORS */
        BitcoinExchange(void);
        BitcoinExchange(std::string data_file);
        BitcoinExchange(const BitcoinExchange &other);

        /* DESTRUCTORS */
        ~BitcoinExchange(void);

        /* OPERATORS */
        BitcoinExchange& operator=(const BitcoinExchange &other);

        /* PUBLIC METHODS */
        void    runBitcoinExchange(std::ifstream &file);
};

#endif