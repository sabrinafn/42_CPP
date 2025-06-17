#include "BitcoinExchange.hpp"

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
    // create object with data file
    BitcoinExchange data = BitcoinExchange("data.csv");

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