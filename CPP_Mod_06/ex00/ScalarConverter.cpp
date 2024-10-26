#include "ScalarConverter.hpp"
#include <cstdlib>	// pour strtol
#include <string>
#include <limits>

bool	is_int_from_double(double doubleValue)
{
	return (doubleValue == static_cast<double>(static_cast<int>(doubleValue)));
}

bool	is_int_from_float(float floatValue)
{
	return (floatValue == static_cast<double>(static_cast<int>(floatValue)));
}

void	handle_char(char charValue)
{
	std::cout << "char: " << "'" << charValue << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(charValue) << std::endl;
	std::cout << "float: " << std::setprecision(PRECISION) << std::fixed << static_cast<float>(charValue) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(PRECISION) << std::fixed << static_cast<double>(charValue) << std::endl;
}

void	handle_int(int intValue)
{
	if (intValue < -128 || intValue > 127)
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
	if (!is_int_from_float(floatValue) || floatValue < -128 || floatValue > 127)
		std::cout << "char: " << "Impossible" << std::endl;
	else if (floatValue < 32 || floatValue > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(floatValue) << "'" << std::endl;
	if (static_cast<int>(floatValue) >= std::numeric_limits<int>::min()
			&& static_cast<int>(floatValue) <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
	else
		std::cout << "int: " << "Impossible" << std::endl;
	std::cout << "float: " << std::setprecision(PRECISION) << std::fixed << floatValue << "f" << std::endl;
	std::cout << "double: " << std::setprecision(PRECISION) << std::fixed << static_cast<double>(floatValue) << std::endl;
}

void	handle_double(double doubleValue)
{
	if (!is_int_from_double(doubleValue) || doubleValue < -128 || doubleValue > 127)
		std::cout << "char: " << "Impossible" << std::endl;
	else if (doubleValue < 32 || doubleValue > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(doubleValue) << "'" << std::endl;
	if (static_cast<int>(doubleValue) >= std::numeric_limits<int>::min()
			&& static_cast<int>(doubleValue) <= std::numeric_limits<int>::max())
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
		std::cout << "float: " << std::setprecision(PRECISION) << std::fixed << static_cast<float>(doubleValue) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(PRECISION) << std::fixed << doubleValue << std::endl;
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
		handle_special(literal);
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "NaNf")
		handle_special(literal.substr(0, literal.size() - 1));
	else if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		charValue = literal[0];
		handle_char(charValue);
	}
	else if (*end_ptr == '\0' && longValue >= std::numeric_limits<int>::min() && longValue <= std::numeric_limits<int>::max())
	{
		intValue = static_cast<int>(longValue);
		handle_int(intValue);
	}
	else if (literal.find(".") != std::string::npos)
	{
		if (literal.find("f") == literal.size() - 1)
		{
			floatValue = strtof(literal.c_str(), &end_ptr);
			if ((floatValue > 0 && floatValue < std::numeric_limits<float>::min())
					|| (floatValue < 0 && floatValue > -(std::numeric_limits<float>::min())))
				handle_impossible();
			else if(floatValue > std::numeric_limits<float>::max())
				handle_special("+inf");
			else if(floatValue < -(std::numeric_limits<float>::max()))
				handle_special("-inf");
			else
				handle_float(floatValue);
		}
		else
		{
			doubleValue = strtod(literal.c_str(), &end_ptr);
			if ((doubleValue > 0 && doubleValue < std::numeric_limits<double>::min())
					|| (doubleValue < 0 && doubleValue > -(std::numeric_limits<double>::min())))
				handle_impossible();
			else if(doubleValue > std::numeric_limits<double>::max())
				handle_special("+inf");
			else if(doubleValue < -(std::numeric_limits<double>::max()))
				handle_special("-inf");
			else
				handle_double(doubleValue);
		}
	}
	else
		handle_impossible();
}
