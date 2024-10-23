#ifndef SCALAR_CONVERTER_H
# define SCLAR_CONVERTER_H

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter
{
	public:
	static void convert (const str::string &literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &);

};

#endif
