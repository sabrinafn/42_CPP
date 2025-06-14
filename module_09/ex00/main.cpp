#include "BitcoinExchange.hpp"

bool is_date_valid(std::string date) {

    // YYYY-MM-DD

    if (date.length() != 10) {
        std::cerr << "data.length is different than 10." << std::endl;
        return false;
    }
    if (date[4] != '-' && date[7] != '-') {
        std::cerr << "date index 4 and 7 are not '-'." << std::endl;
        return false;
    }
    return true;
}

bool is_value_valid(std::string value) {
    (void)value;
    return true;
}

std::map<std::string, float> parse_data_file(std::string arg) {

    std::map<std::string, float> temp; // map to store date and value
    
    std::ifstream file(arg.c_str()); // std::ifstream == open file
    if (!file.is_open()) { // is_open == check if file is open
        std::cerr << "Error. Could not open file." << std::endl;
        temp[0] = -1;
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
            std::cerr << "Invalid data file" << std::endl;
            temp[0] = -1;
            return temp;
        }

        //temp[date] = std::atof(value.c_str()); // convert value to float to store in map
        temp[date] = strtof(value.c_str(), NULL);
    }
    std::cout << "all good here" << std::endl;
    return temp;
}

int main(int ac, char **av) {

    if (ac != 2) {
        std::cerr << "Error! Wrong number of arguments." << std::endl;
        return 1;
    }
    (void)av;
    // parse data.csv received
    std::map<std::string, float> data_file = parse_data_file("data.csv");
    
    // if (data_file[0] == -1) {
    //     std::cerr << "Error! Data file is wrongly formatted." << std::endl;
    //     return 1;
    // }

    // store in class MyMap
    //BitcoinExchange data = BitcoinExchange(data_file);


    return 0;
}