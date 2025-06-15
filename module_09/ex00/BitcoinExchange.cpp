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
        }
        
        std::cout << "date parsed: " << date << std::endl;
        std::cout << "value parsed: " << value << std::endl;
        // validate data before storing
        if (!is_date_valid(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }
        else if (!is_value_valid(value)) {
            std::cerr << "error. date or value invalid from input file." << std::endl;
            continue ;
        }
        // search for date
        

        // calculate the value in input * value in data
        // printe result line by line
    }
}

int BitcoinExchange::get_february_days(int year) {

    if (year % 4 == 0 && year % 100 != 0)
        return 29;
    if (year % 400 == 0 && year % 100 == 0)
        return 29;
    return 28;
}

bool BitcoinExchange::is_date_valid(std::string date) {

    // YYYY-MM-DD
    int year, month, day;

    if (date.length() != 10) {
        std::cerr << "error. data.length is different than 10." << std::endl;
        return false;
    }
    if (date[4] != '-' && date[7] != '-') {
        std::cerr << "error. date index 4 and 7 are not '-'." << std::endl;
        return false;
    }
    // store values separated to validate
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
		std::cerr << "error. couldn't extract 3 values from date" << std::endl;
        return false;
	}
    if (year < 2009 || year > 2022) {
        std::cerr << "error. invalid year in date.csv file" << std::endl;
        return false;
    }
    if (month < 1 || month > 12) {
        std::cerr << "error. invalid month in date.csv file" << std::endl;
        return false;
    }
    
    // days of the month
    int feb = get_february_days(year);
    int days_array[] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > days_array[month - 1]) {
        std::cerr << "error. invalid days in date.csv file" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::is_value_valid(std::string value) {
    
    int sign = 0;
    if (value[0] == '-' || value[0] == '+')
        sign = 1;

    bool has_dot = false;
    for (size_t i = sign; i < value.length(); i++) {
        if (value[i] == '.') {
            if (has_dot) { // more than 1 dot 
                std::cerr << "error. not possible to convert string to float" << std::endl;
                return false;
            }
            has_dot = true;
        } else if (!isdigit(value[i])) {
            std::cerr << "error. not possible to convert string to float" << std::endl;
            return false;
        }
    }
    return true;
}