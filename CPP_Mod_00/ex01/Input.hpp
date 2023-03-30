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
#define BOLDCYAN		"\x1b[36;1m"
#define WHITE			"\x1b[37m"
#define RESET			"\x1b[0m"

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
