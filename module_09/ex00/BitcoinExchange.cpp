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

/* METHODS */

// main method
void BitcoinExchange::runBitcoinExchange(std::string input) {

    // read from file line by line with while loop
    // parse line like with previous data file parsing
    // search for date
    // calculate the value in input * value in data
    // printe result line by line
}