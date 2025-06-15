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
void BitcoinExchange::runBitcoinExchange(std::ifstream file) {

    std::string line; // variable to store lines read from file
    std::string date; // store date from line
    std::string value; // store value from line

    // read from file line by line with while loop
    std::getline(file, line); // skip header from data file
    while (std::getline(file, line);) {
        // parse date and value from input
        size_t delimeter_pos = line.find(" | ");
        if (delimeter_pos != std::string::npos) {
            date = line.substr(0, delimeter_pos);
            value = line.substr(delimeter_pos + 3); // skips 3 characters " | "
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
        
        // validate data before storing
        if (!is_date_valid(date) || !is_value_valid(value)) {
            std::cerr << "error. date or value invalid from input file." << std::endl;
            return ;
        }
        // search for date
        
        // calculate the value in input * value in data
        // printe result line by line
    }
}
