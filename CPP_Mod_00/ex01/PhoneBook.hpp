#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Input.hpp"
#include <iostream>
#include <string>
#include <sstream>

#define MAXENTRIES 2

class	PhoneBook {
	public:

	PhoneBook();
	~PhoneBook();
	void	promptUser();
	void	addContact();
	void	searchContact() const;

	private:

	Contact _contact[MAXENTRIES];
	int		_nbContacts;
};

#endif // PHONEBOOK_HPP
