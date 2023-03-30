#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Input.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class	Contact {
	public:

	Contact();
	~Contact();
	void	setContact();
	void	displayShortContact(const int index) const;
	void	displayFullContact() const;


	private:
	
	std::string	inputField(const std::string& text);
	std::string	_infos[5];
	static	std::string	const	_contactLabels[5];
};

#endif // CONTACT_HPP
