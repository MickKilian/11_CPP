#include "Megaphone.hpp"
#include <iostream>
#include <string>

Megaphone::Megaphone() : _str("* LOUD AND UNBEARABLE FEEDBACK NOISE *") {
}

Megaphone::Megaphone(const std::string& str) : _str(str) {
}

Megaphone::~Megaphone() {
}

void	Megaphone::inputMessage(const std::string& str) {
	_str = str;
}

void	Megaphone::makeUpper() {
	for (int i = 0; i < _str.length(); ++i) {
		_str[i] = std::toupper(_str[i]);
	}
}

void	Megaphone::sayMessage() {
	this->makeUpper();
	std::cout << _str << std::endl;
}
