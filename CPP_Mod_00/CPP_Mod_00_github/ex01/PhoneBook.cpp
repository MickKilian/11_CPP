#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_nbContacts = 0;
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::promptUser() {
	std::string input;

	std::cout << std::endl << BOLDGREEN << "Welcome to my Awesome PhoneBook!" << RESET << std::endl;
	while (not std::cin.eof())
	{
		std::cout << BOLDGREEN << "\n** Main Menu **" << RESET << std::endl;
		std::cout << GREEN << "* Add new contact in PhoneBook (ADD)" << RESET << std::endl;
		std::cout << GREEN << "* Search contact you want to see (SEARCH)" << RESET << std::endl;
		std::cout << GREEN << "* Exit PhoneBook (EXIT)" << RESET << std::endl;
		std::cout << BLUE << "What do you want to do?" << RESET << std::endl;
		while (not Input::getInput(input, ">") and input != "ADD" and input != "SEARCH" and input != "EXIT")
		{
			if (std::cin.eof())
				return;
			else if (input != "ADD" and input != "SEARCH" and input != "EXIT")
				std::cout << RED << "Please enter a valid action (ADD, SEARCH or EXIT)." << RESET << std::endl;
		}
		switch (input[0])
		{
			case 'A':
				this->addContact();
				break;
	
			case 'S':
				this->searchContact();
				break;
	
			case 'E':
				return;
		}
	}
}

void	PhoneBook::addContact() {
	++_nbContacts;
	int	index = _nbContacts - 1;

	if (_nbContacts > MAXENTRIES)
	{
		index = MAXENTRIES - 1;
		for (int i = 0; i < MAXENTRIES - 1; ++i) {
			this->_contact[i] = this->_contact[i + 1];
		}
	}
	_contact[index].setContact();
	if (index != _nbContacts - 1) {
		std::cout << RED << "\noldest contact was removed, and contact #" << index + 1 << " was successfully added." << RESET << std::endl;
		_nbContacts = MAXENTRIES;
	}
	else if (not std::cin.eof()) {
		std::cout << BOLDCYAN << "Contact #" << index + 1 << " was successfully added." << RESET << std::endl;
	}
	return;
}

void	PhoneBook::searchContact() const {
	std::string sinput;
	int			index;

	if (_nbContacts)
	{
		std::cout << BOLDGREEN << "_____________________________________________" << RESET << std::endl;
		std::cout << BOLDGREEN << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << RESET << std::endl;
		for (int i = 0; i < _nbContacts ; ++i) {
			_contact[i].displayShortContact(i);
		}
		std::cout << BOLDGREEN << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << RESET << std::endl;
		std::cout << BOLDGREEN << "\n** SEARCH mode ** " << RESET;
		std::cout << BLUE << "Enter index of contact you are interested in." << RESET << std::endl;
		while (not Input::getInput(sinput, ">") || index < 1 || index > _nbContacts)
		{
			if (std::cin.eof())
				return;
			if (!(std::stringstream(sinput) >> index))
			{
				std::cout << RED << "This input is invalid." << RESET << std::endl;
				std::cout << RED << "Please enter a valid index." << RESET << std::endl;
			}
			else if (index < 1 || index > _nbContacts)
				std::cout << RED << "Please enter a valid index." << RESET << std::endl;
			else
				break;
		}
		_contact[index - 1].displayFullContact();
	}
	else
		std::cout << RED << "Phonebook is empty." << RESET << std::endl;
}
