#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickName(""), _number(""), _secret("") {
}

Contact::Contact(const std::string firstName, const std::string lastName, const std::string nickName, const std::string number, const std::string secret) : _firstName(firstName),
	_lastName(lastName), _nickName(nickName), _number(number), _secret(secret) {
}

Contact::~Contact() {
}

Contact	Contact::defineNewContact() {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string number;
	std::string secret;

	std::cout << BOLDGREEN << "\n** ADD mode ** " << RESET;
	std::cout << BLUE << "Please enter new contact." << RESET << std::endl;
	if (Input::getInput(&firstName, "First name : ")
		|| Input::getInput(&lastName, "Last name : ")
		|| Input::getInput(&nickName, "Nick name : ")
		|| Input::getInput(&number, "Number : ")
		|| Input::getInput(&secret, "Secret : "))
			;
	Contact	newContact(firstName, lastName, nickName, number, secret);
	return newContact;
}

void Contact::displayShortContact(const int index) const {
	std::cout << BOLDGREEN << "|" << RESET;
	std::cout << GREEN << std::setw(10) << index + 1 << BOLDGREEN << "|" << RESET;
	std::cout << GREEN << std::setw(10) << trunc(_firstName) << BOLDGREEN << "|" << RESET;
	std::cout << GREEN << std::setw(10) << trunc(_lastName) << BOLDGREEN << "|" << RESET;
	std::cout << GREEN << std::setw(10) << trunc(_nickName) << BOLDGREEN << "|" << RESET << std::endl;
}

void Contact::displayFullContact() const {
	std::cout << BOLDMAGENTA << "First name : " RESET;
	std::cout << MAGENTA << _firstName << RESET << std::endl;
	std::cout << BOLDMAGENTA << "Last name : " << RESET;
	std::cout << MAGENTA << _lastName << RESET << std::endl;
	std::cout << BOLDMAGENTA << "Nick name : " << RESET;
	std::cout << MAGENTA << _nickName << RESET << std::endl;
	std::cout << BOLDMAGENTA << "Number : " << RESET;
	std::cout << MAGENTA << _number << RESET << std::endl;
	std::cout << BOLDMAGENTA << "Darkest secret : " << RESET;
	std::cout << MAGENTA << _secret << RESET << std::endl;
}

std::string	Contact::inputField(const std::string& text) {
	std::string	input = "";

	while (input == "")
	{
		Input::getInput(&input, text);
	}
	return input;
}

std::string	Contact::trunc(const std::string& text) const {
	std::string	str;

	if (text.length() > 10)
	{
		str = text.substr(0, 10);
		str.replace(9, 1, ".");
	}
	else
		str = text;
	return str;
}
