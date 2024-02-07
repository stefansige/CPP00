/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:39:14 by snovakov          #+#    #+#             */
/*   Updated: 2024/02/07 14:39:15 by snovakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string	fn;
		std::string	ln;
		std::string	nn;
		std::string	pn;
		std::string	ds;
	public:
		Contact()
		{
		}
		void	Initialize()
		{
			std::cout << "Insert First Name" << std::endl;
			while (fn.empty())
				std::cin >> fn;
			std::cout << "Insert Last Name" << std::endl;
			while (ln.empty())
				std::cin >> ln;
			std::cout << "Insert Nick Name" << std::endl;
			while (nn.empty())
				std::cin >> nn;
			std::cout << "Insert Phone Number" << std::endl;
			while (pn.empty())
				std::cin >> pn;
			std::cout << "Insert Darkest Secret" << std::endl;
			while (ds.empty())
				std::cin >> ds;
		}
};

class PhoneBook
{
	private:
		Contact Contacts[7];
};

#endif