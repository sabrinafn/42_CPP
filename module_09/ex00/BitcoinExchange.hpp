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
        std::map<std::string, float> exchange_rates;

        /* PRIVATE METHODS */
        float                           findExchangeRate(const std::string &date) const;
        std::map<std::string, float>    parseDataFile(const std::string &arg) const;
        bool                            isDateValid(const std::string &date) const;
        bool                            isValueValid(const std::string &value, bool check_limits) const;
        int                             getFebruaryDays(int &year) const;
        float                           strToFloat(const std::string &str) const;
        void                            printBadInputMessage(const std::string &msg, const std::string &error) const;
    
        /* consts */
        const std::string LOWEST_DATE;
        const std::string HIGHEST_DATE;

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