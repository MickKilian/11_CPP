#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Input.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class	Contact {
	public:

	Contact();
	Contact(const std::string firstName, const std::string lastName, const std::string nickName, const std::string number, const std::string secret);
	~Contact();
	Contact	defineNewContact();
	void displayShortContact(const int index) const;
	void displayFullContact() const;

	private:
	
	std::string	inputField(const std::string& text);
	std::string	trunc(const std::string& text) const;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_number;
	std::string	_secret;
};

#endif // CONTACT_HPP
