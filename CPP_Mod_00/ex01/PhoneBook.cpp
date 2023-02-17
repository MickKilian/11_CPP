#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contact(), _nbContacts(0)  {
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::promptUser() {
	std::string input;

	std::cout << std::endl << BOLDGREEN << "Welcome to my PhoneBook!" << RESET << std::endl;
	while (not std::cin.eof())
	{
		std::cout << BOLDGREEN << "\n** Main Menu **" << RESET << std::endl;
		std::cout << GREEN << "* Add new contact in PhoneBook (ADD)" << RESET << std::endl;
		std::cout << GREEN << "* Search contact you want to see (SEARCH)" << RESET << std::endl;
		std::cout << GREEN << "* Exit PhoneBook (EXIT)" << RESET << std::endl;
		std::cout << BLUE << "What do you want to do?" << RESET << std::endl;
		while (not Input::getInput(&input, ">") and input != "ADD" and input != "SEARCH" and input != "EXIT")
		{
			if (std::cin.eof())
				return;
			else if (input != "ADD" and input != "SEARCH" and input != "EXIT")
				std::cout << RED << "Please enter a valid action (ADD, SEARCH or EXIT)." << RESET << std::endl;
//				std::cout << "jWhat do you want to do (ADD, SEARCH, EXIT)?" << std::endl;
//				if (!std::cin.eof())
//					std::cin >> input;
//				else
//					return;
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
	Contact	newContact;

	newContact = _contact[0].defineNewContact();
	++_nbContacts;
	if (_nbContacts > MAXENTRIES)
	{
		std::cout << RED << "\nContact #" << MAXENTRIES << " is replaced by new contact." << RESET << std::endl;
		_nbContacts = MAXENTRIES;
	}
	_contact[_nbContacts - 1] = newContact;
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
		//std::cout << BOLDGREEN << "_____________________________________________" << RESET << std::endl;
		std::cout << BOLDGREEN << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << RESET << std::endl;
		std::cout << BOLDGREEN << "\n** SEARCH mode ** " << RESET;
		std::cout << BLUE << "Enter index of contact are you interested in." << RESET << std::endl;
		while (not Input::getInput(&sinput, ">") || index < 1 || index > _nbContacts)
		{
			if (std::cin.eof())
				return;
			std::stringstream (sinput) >> index;
			if (index < 1 || index > _nbContacts)
				std::cout << RED << "Please enter a valid index." << RESET << std::endl;
			else
				break;
		}
		_contact[index - 1].displayFullContact();
	}
	else
		std::cout << RED << "Phonebook is empty." << RESET << std::endl;
}
