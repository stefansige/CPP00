/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:51:42 by snovakov          #+#    #+#             */
/*   Updated: 2024/02/10 17:51:43 by snovakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
				<< "amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return(_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return(_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';'
				<< "total:" << getTotalAmount() << ';'
				<< "deposits:" << getNbDeposits() << ';'
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t rawtime = std::time(NULL);
	tm	*time = std::localtime(&rawtime);
	char	timestamp[20];

	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", time);
	std::cout << timestamp << " ";
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = _amount;
	_totalAmount += deposit;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
				<< "p_amount:" << p_amount << ';'
				<< "deposit:" << deposit << ';'
				<< "amount:" << _amount << ';'
				<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ';'
					<< "p_amount:" << _amount << ';'
					<< "withdrawal:refused" << std::endl;
		return (0);
	}
	int	p_amount = _amount;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "index:" << _accountIndex << ';'
				<< "p_amount:" << p_amount << ';'
				<< "withdrawal:" << withdrawal << ';'
				<< "amount:" << _amount << ';'
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (1);
}

int	Account::checkAmount(void) const
{
	return(_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
				<< "amount:" << _amount << ';'
				<< "deposits:" << _nbDeposits << ';'
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}