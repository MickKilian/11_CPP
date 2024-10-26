#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

#define PRECISION 1

#include <iostream>
#include <iomanip>
#include <string>

class ScalarConverter
{
	public:
	static void convert(const std::string &literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &);

};

#endif
