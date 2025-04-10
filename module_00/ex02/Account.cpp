#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// 1. initialize static variables;
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//2. method to display timestamp
void	Account::_displayTimestamp(void) {

    // how the timestamp should be displayed: [YYYYMMDD_HHMMSS]

    // gets current calendar time
    std::time_t now = std::time(NULL);
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

    // to display the timestamp exactly as the same in the log file received:
    //std::cout << "[19920104_091532] ";
}

// 3. constructor
Account::Account(int initial_deposit) {

    // update the account index equal to the current number of accounts created.
    _accountIndex = _nbAccounts;
    // increment the number of accounts we have
    _nbAccounts += 1;

    // initializing account with the first deposit received
    _amount = initial_deposit;

    //update static variables related to the number of accounts and total amount.
    _totalAmount += initial_deposit;

    _nbDeposits = 0;
    _nbWithdrawals = 0;

    //Output the account creation message in the log's format, including the timestamp.
    //[19920104_091532] index:0;amount:42;created
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";created" << std::endl;
}

// 4. destructor
Account::~Account(void) {
    //[19920104_091532] index:0;amount:47;closed

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";closed" << std::endl;
}

// 5. displayaccountsInfos()
void    Account::displayAccountsInfos(void) {
    // [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
    << ";total:" << _totalAmount
    << ";deposits:" << _totalNbDeposits
    << ";withdrawals:" << _totalNbWithdrawals
    << std::endl;
}

// 6. displayStatus()
void   Account::displayStatus(void) const {
    // [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals
    << std::endl;
}

// 7. makeDeposit()
void	Account::makeDeposit(int deposit) {
    //[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";p_amount:" << _amount
    << ";deposit:" << deposit
    << ";amount:" << _amount + deposit
    << ";nb_deposits:" << _nbDeposits + 1
    << std::endl;

    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
}

// 8. makeWithdrawal()
bool	Account::makeWithdrawal(int withdrawal) {
    //[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";p_amount:" << _amount
    << ";withdrawal:";

    if (withdrawal <= _amount) {  

        std::cout << withdrawal
        << ";amount:" << _amount - withdrawal
        << ";nb_withdrawals:" << _nbWithdrawals + 1
        << std::endl;

        _amount -= withdrawal;
        _nbWithdrawals += 1;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals +=1;
        return true;
    }
    else {
        std::cout << "refused" << std::endl;
        return false;
    }
}

// 9. checkAmount()
int		Account::checkAmount(void) const{
    return _amount;
}