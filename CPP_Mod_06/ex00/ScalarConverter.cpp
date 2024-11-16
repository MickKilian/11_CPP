/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:30:55 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/17 00:27:28 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	handle_char(char charValue)
{
	std::cout << "char: " << "'" << charValue << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(charValue) << std::endl;
	std::cout << "float: " << std::setprecision(PRECISION) << std::fixed << static_cast<float>(charValue) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(PRECISION) << std::fixed << static_cast<double>(charValue) << std::endl;
}

void	handle_int(int intValue)
{
	if (intValue < std::numeric_limits<char>::min() || intValue > std::numeric_limits<char>::max())
		std::cout << "char: " << "Impossible" << std::endl;
	else if (intValue < 32 || intValue > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(intValue) << "'" << std::endl;
	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << std::setprecision(PRECISION) << std::fixed << static_cast<float>(intValue) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(PRECISION) << std::fixed << static_cast<double>(intValue) << std::endl;
}

void	handle_float(float floatValue)
{
	if (floatValue < std::numeric_limits<char>::min() || floatValue > std::numeric_limits<char>::max())
		std::cout << "char: " << "Impossible" << std::endl;
	else if (floatValue < 32 || floatValue > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(floatValue) << "'" << std::endl;
	if (floatValue >= std::numeric_limits<int>::min()
			&& floatValue <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
	else
		std::cout << "int: " << "Impossible" << std::endl;
	if (floatValue == std::floor(floatValue))
		std::cout << "float: " << std::setprecision(PRECISION) << std::fixed << floatValue;
	else
		std::cout << "float: " << floatValue;
	if (floatValue >= 1e+5 && floatValue < 1e+6)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	if (static_cast<double>(floatValue) == std::floor(static_cast<double>(floatValue)))
		std::cout << "double: " << std::setprecision(PRECISION) << std::fixed << static_cast<double>(floatValue);
	else
		std::cout << "double: " << static_cast<double>(floatValue);
	if (static_cast<double>(floatValue) >= 1e+5 && static_cast<double>(floatValue) < 1e+6)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void	handle_double(double doubleValue)
{
	if (doubleValue < std::numeric_limits<char>::min() || doubleValue > std::numeric_limits<char>::max())
		std::cout << "char: " << "Impossible" << std::endl;
	else if (doubleValue < 32 || doubleValue > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(doubleValue) << "'" << std::endl;
	if (doubleValue >= std::numeric_limits<int>::min()
			&& doubleValue <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
	else
		std::cout << "int: " << "Impossible" << std::endl;
	if ((doubleValue > 0 && doubleValue < std::numeric_limits<float>::min())
			|| (doubleValue < 0 && doubleValue > -(std::numeric_limits<float>::min())))
		std::cout << "float: " << "Impossible" << std::endl;
	else if(doubleValue > std::numeric_limits<float>::max())
		std::cout << "float: " << "+inff" << std::endl;
	else if(doubleValue < -(std::numeric_limits<float>::max()))
		std::cout << "float: " << "-inff" << std::endl;
	else
	{
		if (static_cast<float>(doubleValue) == std::floor(static_cast<float>(doubleValue)))
			std::cout << "float: " << std::setprecision(PRECISION) << std::fixed << static_cast<float>(doubleValue);
		else
			std::cout << "float: " << static_cast<float>(doubleValue);
		if (static_cast<float>(doubleValue) >= 1e+5 && static_cast<float>(doubleValue) < 1e+6)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	if (doubleValue == std::floor(doubleValue))
		std::cout << "double: " << std::setprecision(PRECISION) << std::fixed << doubleValue;
	else
		std::cout << "double: " << doubleValue;
	if (doubleValue >= 1e+5 && doubleValue < 1e+6)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void	handle_special(const std::string &special)
{
	std::cout << "char: " << "Impossible" << std::endl;
	std::cout << "int: " << "Impossible" << std::endl;
	std::cout << "float: " << special << "f" << std::endl;
	std::cout << "double: " << special << std::endl;
}

void	handle_impossible(void)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: Impossible" << std::endl;
	std::cout << "double: Impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	char		charValue;
	int			intValue;
	float		floatValue;
	double		doubleValue;
	char		*end_ptr = NULL;
	long		longValue;

	longValue = strtol(literal.c_str(), &end_ptr, 10);
	if (literal == "-inf" || literal == "+inf" || literal == "nan" || literal == "NaN")
	{
		handle_special(literal);
		return ;
	}
	if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "NaNf")
	{
		handle_special(literal.substr(0, literal.size() - 1));
		return ;
	}
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		charValue = literal[0];
		handle_char(charValue);
		return ;
	}
	if (*end_ptr == '\0' && longValue >= std::numeric_limits<int>::min() && longValue <= std::numeric_limits<int>::max())
	{
		intValue = static_cast<int>(longValue);
		handle_int(intValue);
		return ;
	}
	if ((literal.find("f") == literal.size() - 1 || literal.find("F") == literal.size() - 1) && literal.find(".") < literal.size() - 2)
	{
		floatValue = strtof(literal.substr(0, literal.size() - 1).c_str(), &end_ptr);
		if (*end_ptr == '\0')
		{
			if ((floatValue > 0 && floatValue < std::numeric_limits<float>::min())
				|| (floatValue < 0 && floatValue > -(std::numeric_limits<float>::min())))
				handle_impossible();
			else if(floatValue > std::numeric_limits<float>::max())
				handle_special("+inf");
			else if(floatValue < -(std::numeric_limits<float>::max()))
				handle_special("-inf");
			else
				handle_float(floatValue);
			return ;
		}
	}
	doubleValue = strtod(literal.c_str(), &end_ptr);
	if (*end_ptr == '\0')
	{
		if ((doubleValue > 0 && doubleValue < std::numeric_limits<double>::min())
				|| (doubleValue < 0 && doubleValue > -(std::numeric_limits<double>::min())))
			handle_impossible();
		else if(doubleValue > std::numeric_limits<double>::max())
			handle_special("+inf");
		else if(doubleValue < -(std::numeric_limits<double>::max()))
			handle_special("-inf");
		else
			handle_double(doubleValue);
		return ;
	}
	else
		handle_impossible();
}
