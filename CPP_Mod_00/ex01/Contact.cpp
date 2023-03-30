#include "Contact.hpp"

Contact::Contact() {
	for (int i = 0; i < 5; i++) {
		_infos[i] = std::string();
	}
}

Contact::~Contact() {
}

std::string	const	Contact::_contactLabels[5] = { "First name", "Last name", "Nick name", "Number", "Darkest secret" };

void	Contact::setContact() {
	std::cout << BOLDGREEN << "\n** ADD mode ** " << RESET;
	std::cout << BLUE << "Please enter new contact." << RESET << std::endl;
	for (int i = 0; i < 5; i++) {
		if (Input::getInput(this->_infos[i], Contact::_contactLabels[i] + " : "))
			break;
	}
}

void Contact::displayShortContact(const int index) const {
	std::cout << BOLDGREEN << "|" << RESET;
	std::cout << GREEN << std::setw(10) << index + 1 << BOLDGREEN << "|" << RESET;
	for (int i = 0; i < 3; i++) {
		if (this->_infos[i].size() > 10) {
			std::cout << GREEN << std::setw(9) << this->_infos[i].substr(0, 9) << "." << RESET;
		}
		else {
			std::cout << GREEN << std::setw(10) << this->_infos[i] << RESET;
		}
		std::cout << BOLDGREEN << "|" << RESET;
	}
	std::cout << std::endl;
}

void Contact::displayFullContact() const {
	for (int i = 0; i < 5; ++i) {
	std::cout << BOLDMAGENTA << Contact::_contactLabels[i] + " : " RESET;
		std::cout << MAGENTA << _infos[i] << RESET << std::endl;
	}
}

std::string	Contact::inputField(const std::string& text) {
	std::string	input = "";

	while (input == "")
		Input::getInput(input, text);
	return input;
}
