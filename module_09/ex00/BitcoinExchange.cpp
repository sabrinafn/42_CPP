#include "BitcoinExchange.hpp"

/* CONSTRUCTORS */

BitcoinExchange::BitcoinExchange(void)
    : exchange_rates(), LOWEST_DATE("2009-01-02"), HIGHEST_DATE("2022-03-29") {}

BitcoinExchange::BitcoinExchange(std::string data_file) : LOWEST_DATE("2009-01-02"), HIGHEST_DATE("2022-03-29") {

    // parse data.csv received
    std::map<std::string, float> data = parseDataFile(data_file);
    
    if (data.empty()) {
        std::cerr << RED << "Error: data file is incorrectly formatted" << RESET << std::endl;
        return;
    }
    exchange_rates = data;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

/* DESTRUCTORS */
BitcoinExchange::~BitcoinExchange(void) {}

/* OPERATORS */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->exchange_rates = other.exchange_rates;
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
    //std::getline(file, line); // skip header from data file
    while (std::getline(file, line)) {
        if (line == "date | value\r" || line == "date | value")
            std::getline(file, line); 
        // parse date and value from input
        size_t delimiter_pos = line.find(" | ");
        if (delimiter_pos != std::string::npos) {
            date = line.substr(0, delimiter_pos);
            value = line.substr(delimiter_pos + 3); // skips 3 characters " | "
        } else {
            printBadInputMessage("bad input", line);
            continue ;
        }

        // remove '\r' at the end of every line
        value.erase(std::remove(value.begin(), value.end(), '\r'), value.end());

        // validate data before storing
        int year;
        sscanf(date.c_str(), "%d-%*d-%*d", &year);
        if (!isDateValid(date) || year < 2009) {
            printBadInputMessage("invalid date", date);
            continue ;
        }
        else if (!isValueValid(value, true)) {
            continue ;
        }

        // search for date
        float rate_found = findExchangeRate(date);
        
        // calculate the value in input * value in data
        float result = rate_found * strToFloat(value);

        // printe result line by line
        std::cout << GREEN << date << " => " << value << " = " << result << RESET << std::endl;
    }
}

float BitcoinExchange::findExchangeRate(const std::string &date) const {
    
    if (date > HIGHEST_DATE) {
        return exchange_rates.find(HIGHEST_DATE)->second;
    }
    
    std::map<std::string, float>::const_iterator it = exchange_rates.lower_bound(date);
    if (it != exchange_rates.end() && it->first != date) {
        it--;
    }
    return it->second;
}

bool BitcoinExchange::isDateValid(const std::string &date) const {

    // YYYY-MM-DD
    int year, month, day;

    if (date.empty()) {
        printBadInputMessage("invalid date", date);
        return false;
    }
    if (date < LOWEST_DATE) {
        return false;
    }
    // syntax check
    if ((date.length() != 10) || (date[4] != '-' || date[7] != '-')) {
        return false;
    }
    
    // store values separated to validate
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        return false;
	}
    if (month < 1 || month > 12)
        return false;
    
    // days of the month
    int feb = getFebruaryDays(year);
    int days_array[] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > days_array[month - 1])
        return false;
    
    return true;
}

bool BitcoinExchange::isValueValid(const std::string &value, bool check_limits) const {
    
    if (value.empty()) {
        printBadInputMessage("invalid value", value);
        return false;
    }

    int sign = 0;
    if (value[0] == '-' || value[0] == '+')
        sign = 1;

    bool has_dot = false;
    for (size_t i = sign; i < value.length(); i++) {
        if (value[i] == '.') {
            if (has_dot) { // more than 1 dot
                printBadInputMessage("invalid value", value);
                return false;
            }
            has_dot = true;
        } else if (!isdigit(value[i])) {
            printBadInputMessage("invalid value", value);
            return false;
        }
    }

    if (check_limits) {
        float f = strToFloat(value);
        if (f < 0) {
            printBadInputMessage("not a positive number", value);
            return false;
        }
        if (f > 1000) {
            printBadInputMessage("too large a number", value);
            return false;
        }
    }
    return true;
}

std::map<std::string, float> BitcoinExchange::parseDataFile(const std::string &arg) const {

    std::map<std::string, float>    temp; // map to store date and value
    std::string                     line; // variable to store lines read from file
    std::string                     date; // store date from line
    std::string                     value; // store value from line
    
    std::ifstream file(arg.c_str()); // std::ifstream == open file
    if (!file.is_open()) { // is_open == check if file is open
        std::cerr << RED << "Error: failed to open the data file" << RESET << std::endl;
        return temp;
    }

    std::getline(file, line); // skip header from data file
    while (std::getline(file, line)) { // gets one line at a time from file
        
        // parse date and value
        size_t delimiter_pos = line.find(",");
        if (delimiter_pos != std::string::npos) {
            date = line.substr(0, delimiter_pos);
            value = line.substr(delimiter_pos + 1); // 1 for ','
        }
        // validate data before storing
        if (!isDateValid(date) || !isValueValid(value, false)) {
            std::cerr << RED << "Error: Invalid line in data file: " << line << RESET << std::endl;
            return temp;
        }
        temp[date] = strToFloat(value); // convert value to float to store in map
    }
    return temp;
}

// short-helper functions

void BitcoinExchange::printBadInputMessage(const std::string &msg, const std::string &error) const {
   std::cerr << RED << "Error: " << msg << " => " << error << RESET << std::endl;
}

int BitcoinExchange::getFebruaryDays(int year) const {

    // calculations to identify if a year is a leap year or not
    if (year % 4 == 0 && year % 100 != 0)
        return 29;
    if (year % 400 == 0 && year % 100 == 0)
        return 29;
    return 28;
}

float BitcoinExchange::strToFloat(const std::string &str) const{
    std::stringstream txt_file(str);
    float f;
    txt_file >> f;
    return f;
}