#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// 1. initialize static variables to 0;
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//2. initialize displaytimestamp
// how the time should be displayed: [YYYYMMDD_HHMMSS]
void	Account::_displayTimestamp( void ) {
    // gets current calendar time
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    std::cout << "["
              << 1900 + localTime->tm_year // Year (since 1900)
              << std::setfill('0') << std::setw(2) << 1 + localTime->tm_mon // Month (0-11)
              << std::setw(2) << localTime->tm_mday // Day (1-31)
              << "_"
              << std::setw(2) << localTime->tm_hour // Hour (0-23)
              << std::setw(2) << localTime->tm_min // Minute (0-59)
              << std::setw(2) << localTime->tm_sec // Second (0-59)
              << "] ";
}

Account::Account(int initial_deposit) {
    _accountIndex = 
    _amount = initial_deposit;
    //update static variables related to the number of accounts and total amount.
    //Output the account creation message in the log's format, including the timestamp.
}

Account::~Account( void ) {

}