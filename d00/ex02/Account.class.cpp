/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:45:47 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/29 20:57:09 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

Account::Account(int initial_deposit) : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
    this->_amount += initial_deposit;
    this->_accountIndex = Account::_nbAccounts;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;

    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
    std::cout << ";closed" << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    int p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount;
    std::cout << ";deposit:" << deposit << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    if (withdrawal >= this->_amount)
    {
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
        int p_amount = this->_amount;
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals += 1;

        std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount;
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount;
        std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    }
    return (true);
}

void    Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" <<  Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits;
    std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void    Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void)
{
    time_t tt;
    struct tm *ti;
    time(&tt);
    ti = localtime(&tt);
    
    std::cout << "[" << ti->tm_year + 1900;
    std::cout.setf(std::ios::right);
    std::cout << std::setfill('0') << std::setw(2) << ti->tm_mon;
    std::cout << std::setfill('0') << std::setw(2) << ti->tm_mday;
    std::cout << "_";
    std::cout << std::setfill('0') << std::setw(2) << ti->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << ti->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << ti->tm_sec;
    std::cout << "] ";
    std::cout.unsetf(std::ios::right);
}

int Account::checkAmount() const
{
    return (this->_amount);
}

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}
	
int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;