#include "BitcoinExchange.hpp"

// std::map<std::string, float> container;
    
/* CONSTRUCTORS */

BitcoinExchange::BitcoinExchange(void) : container(){}
BitcoinExchange::BitcoinExchange(std::string data_file) {

    // parse data.csv received
    std::map<std::string, float> data = parseDataFile(data_file);
    
    if (data.empty()) {
        std::cerr << "Error! Data file is wrongly formatted." << std::endl;
        return;
    }
    container = data;
}
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
            printBadInput(line);
            continue ;
        }

        // remove '\r' at the end of every line
        value.erase(std::remove(value.begin(), value.end(), '\r'), value.end());

        // validate data before storing
        int year;
        sscanf(date.c_str(), "%d-%*d-%*d", &year);
        if (!isDateValid(date) || year < 2009) {
            printBadInput(date);
            continue ;
        }
        else if (!isValueValid(value, true)) {
            continue ;
        }

        // search for date
        float exchange_rate = findExchangeRate(date);
        
        // calculate the value in input * value in data
        std::stringstream txt_file(value); // stringstream acts likea file
        float f;
        txt_file >> f;
        float result = exchange_rate * f;

        // printe result line by line
        std::cout << GREEN << date << " => " << value << " = " << result << RESET << std::endl;
    }
}

float BitcoinExchange::findExchangeRate(std::string date) const {
    
    std::map<std::string, float>::const_iterator it = container.lower_bound(date);

    if (it != container.end() && it->first != date) {
        if (it == container.begin())
            std::cerr << "no earlier date available" << std::endl;
        else {
            it--;
            //std::cout << "closest found: " << it->first << std::endl;
        }
    }
    else if (it != container.end()) {
        //std::cout << "exact date found: " << it->first << std::endl;
    }
    return it->second;
}

bool BitcoinExchange::isDateValid(std::string date) const {

    // YYYY-MM-DD
    int year, month, day;

    if (date.length() != 10) {
        //std::cerr << "error. data.length is different than 10." << std::endl;
        return false;
    }
    if (date[4] != '-' && date[7] != '-') {
        //std::cerr << "error. date index 4 and 7 are not '-'." << std::endl;
        return false;
    }
    // store values separated to validate
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
		//std::cerr << "error. couldn't extract 3 values from date" << std::endl;
        return false;
	}
    if (year < 2009 || year > 2022) {
        //std::cerr << "error. invalid year" << std::endl;
        return false;
    }
    if (month < 1 || month > 12) {
        //std::cerr << "error. invalid month in date.csv file" << std::endl;
        return false;
    }
    
    // days of the month
    int feb = getFebruaryDays(year);
    int days_array[] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > days_array[month - 1]) {
        //std::cerr << "error. invalid days in date.csv file" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValueValid(std::string value, bool check_limits) const {
    
    if (value.empty())
        return false;
    int sign = 0;
    if (value[0] == '-' || value[0] == '+')
        sign = 1;

    bool has_dot = false;
    for (size_t i = sign; i < value.length(); i++) {
        if (value[i] == '.') {
            if (has_dot) { // more than 1 dot 
                printBadInput(value);
                return false;
            }
            has_dot = true;
        } else if (!isdigit(value[i])) {
            printBadInput(value);
            return false;
        }
    }

    if (check_limits) {
        std::stringstream ss(value); // stringstream acts like a file
        float f;
        ss >> f;
        if (f < 0) {
            std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
            return false;
        }
        if (f > 1000) {
            std::cerr << RED << "Error: too large a number." << RESET << std::endl;
            return false;
        }
    }
    return true;
}

std::map<std::string, float> BitcoinExchange::parseDataFile(std::string arg) const {

    std::map<std::string, float> temp; // map to store date and value
    
    std::ifstream file(arg.c_str()); // std::ifstream == open file
    if (!file.is_open()) { // is_open == check if file is open
        std::cerr << "Error. Could not open data file." << std::endl;
        return temp;
    }
    std::string line; // variable to store lines read from file
    std::string date; // store date from line
    std::string value; // store value from line
   
    std::getline(file, line); // skip header from data file
    while (std::getline(file, line)) { // gets one line at a time from file
        
        // parse date and value
        size_t delimeter_pos = line.find(" | ");
        if (delimeter_pos != std::string::npos) {
            date = line.substr(0, delimeter_pos);
            value = line.substr(delimeter_pos + 3); // skips 3 characters " | "
        }

        // validate data before storing
        if (!isDateValid(date) || !isValueValid(value, false)) {
            return temp;
        }
        temp[date] = strtof(value.c_str(), NULL);  // convert value to float to store in map
    }
    //std::cout << "all good here" << std::endl;
    return temp;
}

// Helper short-functions

void BitcoinExchange::printBadInput(std::string &line) const {
    std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
}

int BitcoinExchange::getFebruaryDays(int year) const {

    if (year % 4 == 0 && year % 100 != 0)
        return 29;
    if (year % 400 == 0 && year % 100 == 0)
        return 29;
    return 28;
}