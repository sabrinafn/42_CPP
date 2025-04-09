// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t; // Account == t

	static int	getNbAccounts( void ); // total number os account objects created
	static int	getTotalAmount( void ); // sum of all account balances
	static int	getNbDeposits( void ); //total number of deposits made across all accounts
	static int	getNbWithdrawals( void ); // total number of withdraws made across all accounts
	static void	displayAccountsInfos( void ); // display the whole document

	Account( int initial_deposit ); // constructor - initial deposit being initialized
	~Account( void ); // destructor

	void	makeDeposit( int deposit ); // add a deposit
	bool	makeWithdrawal( int withdrawal ); // withdraw an amount
	int		checkAmount( void ) const; // checks the account balance
	void	displayStatus( void ) const; // display current status of the account
										 // index:X;amount:Y;deposits:0;withdrawals:0


private:

	static int	_nbAccounts; // total number of accounts
	static int	_totalAmount; // sum of all account balances
	static int	_totalNbDeposits; // total number of deposits made across all accounts
	static int	_totalNbWithdrawals; // total number of withdraws made across all accounts

	// display timestamp in the output
	// it should output like this: [19920104_091532]
	static void	_displayTimestamp( void );

	int				_accountIndex; // account index
	int				_amount; // current account balance
	int				_nbDeposits; // number of deposits made in this account
	int				_nbWithdrawals; // number of withdraws made in this account

	Account( void ); // private constructor

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
