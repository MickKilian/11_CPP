/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:52:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/24 19:32:25 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char* av[])
{
	BitcoinExchange bitcoin;

	if (ac != 2)
		std::cerr << RED << "Usage: ./btc [input file name]" << RESET << std::endl;
	else
	{
		try
		{
			bitcoin.readCSV("data.csv");
			bitcoin.readTXT(av[1]);
		}
		catch (std::exception &e)
		{	
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}

	return 0;
}
