#include "BitcoinExchange.hpp"

int get_february_days(int year) {

    if (year % 4 == 0 && year % 100 != 0)
        return 29;
    if (year % 400 == 0 && year % 100 == 0)
        return 29;
    return 28;
}

bool is_date_valid(std::string date) {

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

bool FindCharOneOccurrence(const std::string& value, char c) {
    
    int count = 0;
    for (size_t i = 0; i < value.length(); i++) {
        if (value[i] == c)
            ++count;
    }
    if (count == 1)
        return true;
    return false;
}

bool get_float(const std::string &value, float &f) {

    if (FindCharOneOccurrence(value, '.') == true) {
        int sign = 0;
        if (value[0] == '-' || value[0] == '+')
            sign = 1;
        for (size_t i = sign; i < value.length(); i++) {
            if (!isdigit(value[i]) && value[i] != '.')
                return false;
        }
        f = strtof(value.c_str(), NULL);
        return true;
    }
    else {
        int sign = 0;
        if (value[0] == '-' || value[0] == '+')
            sign = 1;
        for (size_t i = sign; i < value.length(); i++) {
            if (!isdigit(value[i]))
                return false;
        }
        f = strtof(value.c_str(), NULL);
        return true;
    }
    return false;
}

bool is_value_valid(std::string value) {
    
    float f;
    if (!get_float(value, f)) { 
        std::cerr << "error. not possible to convert string to float" << std::endl;
        return false;
    }
    return true;
}

std::map<std::string, float> parse_data_file(std::string arg) {

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
        std::istringstream ss(line); // splits string into tokens

        std::getline(ss, date, ','); // get line data before the comma
        std::getline(ss, value); // get line data that is leftover
        
        // validate data before storing
        if (!is_date_valid(date) || !is_value_valid(value)) {
            return temp;
        }
        temp[date] = strtof(value.c_str(), NULL);  // convert value to float to store in map
    }
    std::cout << "all good here" << std::endl;
    return temp;
}

int main(int ac, char **av) {

    if (ac != 2) {
        std::cerr << "Error! Wrong number of arguments." << std::endl;
        return 1;
    }
    std::ifstream input_file(av[1]); // std::ifstream == open file
    if (!input_file.is_open()) { // is_open == check if file is open
        std::cerr << "Error. Could not open file received as argument." << std::endl;
        return 1;
    }
    // parse data.csv received
    std::map<std::string, float> data_file = parse_data_file("data.csv");
    
    if (data_file.empty()) {
        std::cerr << "Error! Data file is wrongly formatted." << std::endl;
        return 1;
    }

    // store in object data from class BitcoinExchange
    BitcoinExchange data = BitcoinExchange(data_file);

    data.runBitcoinExchange(input_file);

    return 0;
}

/* 
* Calculates how much a certain amount of Bitcoin was worth on a
* given date based on historical exchange rates.
* 
* data.csv = database of Bitcoin prices over time
* input files = how much X Bitcoin was worth on Y date
*/