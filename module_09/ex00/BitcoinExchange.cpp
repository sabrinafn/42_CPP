#include "BitcoinExchange.hpp"

// std::map<std::string, float> container;
    
/* CONSTRUCTORS */

BitcoinExchange::BitcoinExchange(void) : container(){}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> &data)
    : container(data) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

/* DESTRUCTORS */
BitcoinExchange::~BitcoinExchange(void) {}

/* OPERATORS */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->container = other.container;
    }
    return *this;
}

bool BitcoinExchange::data_valid(std::map<std::string, float> data) {
    
    // check if date is YYYY-MM-DD
    if (data.string[])
    // check if value is positive, float/int, 0 to 1000
    
    return true;
}