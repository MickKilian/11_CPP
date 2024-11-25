/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:51:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/24 19:49:36 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_H
# define BITCOIN_EXCHANGE_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>

#define RED				"\x1b[31m"
#define GREEN			"\x1b[32m"
#define YELLOW			"\x1b[33m"
#define RESET			"\x1b[0m"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		std::map<std::string, double>	getValues(void);
		void							readCSV(const std::string &);
		void							readTXT(const std::string &);
		std::string						searchRefDate(const std::string &);
		static void						compute(const std::string &);

	class TooLargeNumberException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: too large a number => ");
			}
	};

	class NotAPositiveNumberException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: not a positive number => ");
			}
	};

	class BadInputException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: bad input => ");
			}
	};

	private:
		std::map<std::string, double>	_values;

};

#endif
