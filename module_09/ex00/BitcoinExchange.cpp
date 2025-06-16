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
void BitcoinExchange::runBitcoinExchange(std::ifstream &file) {

    std::string line; // variable to store lines read from file
    std::string date; // store date from line
    std::string value; // store value from line

    // read from file line by line with while loop
    std::getline(file, line); // skip header from data file
    while (std::getline(file, line)) {
        // parse date and value from input
        size_t delimeter_pos = line.find(" | ");
        if (delimeter_pos != std::string::npos) {
            date = line.substr(0, delimeter_pos);
            value = line.substr(delimeter_pos + 3); // skips 3 characters " | "
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }

        // remove '\r' at the end of every line
        value.erase(std::remove(value.begin(), value.end(), '\r'), value.end());

        // validate data before storing
        if (!is_date_valid(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            date.clear();
            value.clear();
            continue ;
        }
        else if (!is_input_value_valid(value)) {
            date.clear();
            value.clear();
            continue ;
        }

        //std::cout << "date parsed: [" << date << "] ";
        //std::cout << "value parsed: [" << value << "]" << std::endl;

        // search for date
        

        // calculate the value in input * value in data
        // printe result line by line
        std::cerr << date << " => " << value << " = X" << std::endl;
        date.clear();
        value.clear();
    }
}

bool is_input_value_valid(std::string value) {
    
    if (value.empty()) {
        return false;
    }
    int sign = 0;
    if (value[0] == '-' || value[0] == '+')
        sign = 1;

    bool has_dot = false;
    for (size_t i = sign; i < value.length(); i++) {
        if (value[i] == '.') {
            if (has_dot) { // more than 1 dot 
                std::cerr << "jjerror. not possible to convert string to float" << std::endl;
                return false;
            }
            has_dot = true;
        } else if (!isdigit(value[i])) {
            std::cout << "value[i] = [" << value[i] << "]" << std::endl;
            std::cerr << "kkerror. not possible to convert string to float" << std::endl;
            return false;
        }
    }
    std::stringstream ss(value); // stringstream acts like a file
    int i;
    ss >> i;
    if (i < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (i > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}