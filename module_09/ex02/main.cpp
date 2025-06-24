#include "PmergeMe.hpp"
#include <iomanip>

int main(int ac, char **av) {
    
    if (ac == 1) {
        std::cerr << "Error: missing argument" << std::endl;
        return 1;
    }

    try {

        //std::time_t start_time = std::time(NULL);
        //std::cout << "std::time_t start = " << start_time << std::endl;

        //std::clock_t start = std::clock();
        //for (int i = 0; i < 1000000; i++); // simulating stuff happening
        //std::clock_t end = std::clock();
        //double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        //std::cout << "Time taken: " << duration << " seconds" << std::endl;


        PmergeMe unsorted = PmergeMe();
        unsorted.parseInput(ac, av);
        unsorted.sort();

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}