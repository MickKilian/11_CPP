/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:52:20 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/24 19:54:56 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

std::map<std::string, double>	BitcoinExchange::getValues(void)
{
	return (_values);
}

bool	isValidDate(const std::string &date)
{
	std::istringstream	lineStream(date);
	int					date_split[3];
	std::string			part;

	for (size_t i = 0; i < 3 && std::getline(lineStream, part, '-'); ++i)
	{
		date_split[i] = strtod(part.c_str(), NULL);
	}
	if (date_split[0] > 2024)
		return (false);
	else if (date_split[1] < 1 || date_split[1] > 12)
		return (false);
	else if (date_split[2] < 1 || date_split[2] > 31)
		return (false);
	if (date_split[1] == 2 && date_split[2] > 29)
		return (false);
	if (date_split[1] == 4 || date_split[1] == 6 || date_split[1] == 9 || date_split[1] == 11)
	{
		if (date_split[2] == 31)
			return (false);
	}
	return (true);
}

double	parseDouble(const std::string &doubleStr)
{
	char	*end_ptr = NULL;
	double	nb_parts = strtod(doubleStr.c_str(), &end_ptr);

	if (*end_ptr == '\0' && nb_parts >= 0)
	{
		if (nb_parts > 2147483647)
			throw BitcoinExchange::TooLargeNumberException();
		else
			return (nb_parts);
	}
	else
		throw BitcoinExchange::NotAPositiveNumberException();
}

std::string	BitcoinExchange::searchRefDate(const std::string &date)
{
	std::map<std::string, double>::iterator	it_temp = _values.begin();

	if (it_temp->first > date)
		return ("x" + it_temp->first);
	for (std::map<std::string, double>::iterator it = _values.begin(); it != _values.end(); ++it)
	{
		if (it->first > date)
			return (it_temp->first);
		it_temp = it;
	}
	return (it_temp->first);
}

void	BitcoinExchange::readCSV(const std::string &input)
{
	std::ifstream	inFile(input.c_str());
	std::string		line;
	double			date_value;

	if(!inFile.is_open())
		throw std::ifstream::failure(input + " : File could not be open.");
	std::getline(inFile, line);
	while (std::getline(inFile, line))
	{
		std::istringstream	lineStream(line);
		std::string			date, doubleStr;
		if (std::getline(lineStream, date, ',') && std::getline(lineStream, doubleStr))
		{
			date_value = parseDouble(doubleStr);
			if (isValidDate(date))
			{
				if (date_value == -1)
					std::cerr << RED << "Error: not a positive number. " << doubleStr << RESET << std::endl;
				else if (date_value == -2)
					std::cout << RED << "Error: too large a number. " << doubleStr << RESET << std::endl;
				else
					_values[date] = date_value;
			}
			else
				std::cout << RED << "Invalid Entry: " << line << RESET << std::endl;
		}
		else
			std::cout << RED << "Error : Malformed Line: " << line << RESET << std::endl;
	}
	inFile.close();
}

void	BitcoinExchange::readTXT(const std::string &input)
{
	std::ifstream	inFile(input.c_str());
	std::string		line;
	std::string		date_ref;
	double			nb_parts;

	if(!inFile.is_open())
		throw std::ifstream::failure(input + " : File could not be open.");
	std::getline(inFile, line);
	while (std::getline(inFile, line))
	{
		std::istringstream	lineStream(line);
		std::string			date, doubleStr;
		std::getline(lineStream, date, '|');
		std::getline(lineStream, doubleStr);
		try
		{
			if (!isValidDate(date))
				throw BitcoinExchange::BadInputException();
			date_ref = searchRefDate(date);
			if (date_ref[0] == 'x')
				std::cout << RED << "Error: bad input => " << date << " must be after " << date_ref.erase(0, 1) << RESET << std::endl;
			try
			{
				nb_parts = parseDouble(doubleStr);
			}
			catch (std::exception &e)
			{
				std::cerr << RED << e.what() << doubleStr << RESET << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << date << RESET << std::endl;
		}
		std::cout << date << " => " << nb_parts << " = " << nb_parts * getValues()[searchRefDate(date)] << std::endl;
	}
	inFile.close();
}
