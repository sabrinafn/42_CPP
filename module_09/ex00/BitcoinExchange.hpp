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
        std::map<std::string, float> container;

        float                           findExchangeRate(std::string date) const;
        //void                            printBadInput(std::string &line) const;
        std::map<std::string, float>    parseDataFile(std::string arg) const;
        bool                            isDateValid(std::string date) const;
        int                             getFebruaryDays(int year) const;
        bool                            isValueValid(std::string value, bool check_limits) const;
        float                           strToFloat(std::string &str) const;
    
    public:
        
        /* CONSTRUCTORS */
        BitcoinExchange(void);
        BitcoinExchange(std::string data_file);
        BitcoinExchange(const BitcoinExchange &other);

        /* DESTRUCTORS */
        ~BitcoinExchange(void);

        /* OPERATORS */
        BitcoinExchange& operator=(const BitcoinExchange &other);

        /* METHODS */
        void    runBitcoinExchange(std::ifstream &file);

};

#endif