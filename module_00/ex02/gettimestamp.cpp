#include <iostream>
#include <iomanip>
#include <ctime>

void	displayTimestamp() {
    // gets current calendar time
    std::time_t now = std::time(NULL);

    std::tm* localTime = std::localtime(&now);

    std::cout << "["
              << 1900 + localTime->tm_year // Year (since 1900)
              << std::setfill('0') << std::setw(2) 
              << 1 + localTime->tm_mon // Month (0-11)
              << std::setw(2) << localTime->tm_mday // Day (1-31)
              << "_"
              << std::setw(2) << localTime->tm_hour // Hour (0-23)
              << std::setw(2) << localTime->tm_min // Minute (0-59)
              << std::setw(2) << localTime->tm_sec // Second (0-59)
              << "] ";
}

int main(void)
{
    displayTimestamp();
}