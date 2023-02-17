#ifndef MEGAPHONE_HPP
#define MEGAPHONE_HPP

#include <string>

class Megaphone
{
	public:

	Megaphone();
	Megaphone(const std::string& str);
	~Megaphone();
	void	inputMessage(const std::string& str);
	void	sayMessage();

	private:

	void	makeUpper();
	std::string	_str;
};

#endif
