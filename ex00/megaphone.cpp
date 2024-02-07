/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:16:36 by snovakov          #+#    #+#             */
/*   Updated: 2024/02/07 12:16:38 by snovakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int y;

	i = 1;
	if (argc >= 2)
	{
		while (argv[i])
		{
			y = 0;
			while (argv[i][y])
			{
				if (argv[i][y] >= 'a' && argv[i][y] <= 'z')
					std::cout << static_cast<char>(argv[i][y] - 32);
				else
					std::cout << argv[i][y];
				y++;
			}
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}