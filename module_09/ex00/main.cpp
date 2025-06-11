#include "BitcoinExchange.hpp"

bool data_valid(std::map<std::string, float> data) {
    
    // check if date is YYYY-MM-DD

    // check if value is positive, float/int, 0 to 1000
    
    return true;
}

bool validade_data(std::string arg) {

    std::ifstream file(arg); // std::ifstream == open file
    if (!file.is_open()) { // is_open == check if file is open
        std::cerr << "Error. Could not open file." << std::endl;
        return false;
    }
    std::string line; // variable to store lines read from file
    std::string date; // store date from line
    std::string value; // store value from line
    std::map<std::string, float> temp; // map to store date and value
    while (std::getline(file, line)) { // gets one line at a time from file
        std::istringstream ss(line); // splits string into tokens

        std::getline(ss, date, ','); // get line data before the comma
        std::getline(ss, value); // get line data that is leftover

        temp[date] = std::atof(value.c_str()); // convert value to float to store in map
    }
    if (!data_valid(temp)) {
        std::cerr << "Error. Data in file is wrongly formatted!!!" << std::endl;
        return false;
    }
    return true;
}

int main(int ac, char **av) {

    if (ac != 2)
        std::cerr << "Error! Wrong number of arguments." << std::endl;
    
    // validade data.csv received
    if (!validade_data(av[1]))
        std::cerr << "Error! Data file is wrongly formatted." << std::endl;
    // store in class MyMap
    


    return 0;
}