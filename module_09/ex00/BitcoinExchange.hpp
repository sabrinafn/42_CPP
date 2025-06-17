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

        float find_exchange_rate(std::string date) const;
        void printBadInput(std::string &line) const;
        std::map<std::string, float> parse_data_file(std::string arg) const;
        bool is_date_valid(std::string date) const;
        int get_february_days(int year) const;
        bool is_value_valid(std::string value, bool check_limits) const;
    
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
        void runBitcoinExchange(std::ifstream &file);

};

#endif