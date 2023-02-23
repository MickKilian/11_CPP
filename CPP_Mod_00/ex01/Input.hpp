#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <string>
#include <sstream>

#define RED				"\x1b[31m"
#define GREEN			"\x1b[32m"
#define BOLDGREEN		"\x1b[32;1m"
#define YELLOW			"\x1b[33m"
#define BLUE			"\x1b[34m"
#define MAGENTA			"\x1b[35m"
#define BOLDMAGENTA		"\x1b[35;1m"
#define CYAN			"\x1b[36m"
#define WHITE			"\x1b[37m"
#define RESET			"\x1b[0m"
\x1b[48;2;008;000;000m

"\x1b"
int n = 0xff;
int a = 255;
char c = 255;
const char* str = "\023";

class	Input {
	public:
	static int	getInput( std::string&,
					const std::string& = "",
					const std::string& = BLUE);

	private:
	static int	checkInput(const std::string& input);
	static std::string	split(const std::string& str);
};

#endif
