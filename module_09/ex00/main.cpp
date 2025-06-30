#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

    if (ac != 2) {
        std::cerr << "Error: wrong number of arguments." << std::endl;
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }
    
    std::ifstream input_file(av[1]);
    if (!input_file.is_open()) {
        std::cerr << "Error: failed to open the input file: " << av[1] << std::endl;
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }
    else if (input_file.peek() == EOF) {
        std::cerr << "Error: empty file: " << av[1] << std::endl;
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
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
* input file received on command line = how many Bitcoin we had on a certain date
*/