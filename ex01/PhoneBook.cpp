/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:39:02 by snovakov          #+#    #+#             */
/*   Updated: 2024/02/07 14:39:03 by snovakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>

void	set(std::string& input, std::string text)
{
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert " << text << std::endl;
		std::cin >> input;
	}
}

int	main()
{
	PhoneBook 	phoneBook1;
	std::string	input;
	int			c;
	int			i;
	
	c = 0;
	while (true)
	{
		std::cout << "Insert 'ADD' to save a new contact, insert 'SEARCH' to display a specific contact, insert 'EXIT' to quit the program" << std::endl;
		std::cin >> input;
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
		{
			set(input, "First Name");
			phoneBook1.Contacts[c].firstName = input;
			set(input, "Last Name");
			phoneBook1.Contacts[c].lastName = input;
			set(input, "Nickname");
			phoneBook1.Contacts[c].nickName = input;
			set(input, "Phone Number");
			phoneBook1.Contacts[c].phoneNumber = input;
			set(input, "Darkest Secret");
			phoneBook1.Contacts[c].darkestSecret = input;
			if (c < 7)
				c++;
		}
		else if (input == "SEARCH")
		{
			i = 0;
			std::cout << std::setw(10) << std::right << "Index" << " | "
						<< std::setw(10) << "First Name" << " | "
						<< std::setw(10) << "Last Name" << " | "
						<< std::setw(10) << "Nick Name" << std::endl;
			while (i <= 7)
			{
				std::cout << std::setw(10) << std::right << char(i + '1') << " | "
							<< std::setw(10) << phoneBook1.Contacts[i].firstName.substr(0, 10) << " | "
							<< std::setw(10) << phoneBook1.Contacts[i].lastName.substr(0, 10) << " | "
							<< std::setw(10) << phoneBook1.Contacts[i].nickName.substr(0, 10) << std::endl;
				i++;
			}
			std::cout << "Insert a index to display from 1 to 8" << std::endl;
			input.clear();
			while (input.empty())
			{
				std::cin >> input;
				if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
				{
					std::cout << "First Name: " << phoneBook1.Contacts[int(input[0] - '1')].firstName << std::endl
								<< "Last Name: " << phoneBook1.Contacts[int(input[0] - '1')].lastName << std::endl
								<< "Nick Name: " << phoneBook1.Contacts[int(input[0] - '1')].nickName << std::endl
								<< "Phone Number: " << phoneBook1.Contacts[int(input[0] - '1')].phoneNumber << std::endl
								<< "Darkest Secret: " << phoneBook1.Contacts[int(input[0] - '1')].darkestSecret << std::endl;
				}
				else
				{
					std::cout << "Invalid index" << std::endl;
					input.clear();
				}
			}
			input.clear();
		}
	}
}