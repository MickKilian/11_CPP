/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:32:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 21:52:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("undetermined_animal") {
	std::cout << BOLDWHITE << "WrongAnimal " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
	std::cout << BOLDWHITE << "WrongAnimal " << BLUE << "copy constructor " << RESET << "is called for : " << CYAN << this->_type << RESET << "." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << BOLDWHITE << "WrongAnimal " << RED << "destructor " << RESET << "is called for : " << CYAN << this->_type << RESET << "." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Assignment operator has been called for : " << CYAN << this->_type << RESET <<"." << std::endl;
	return (*this);
}

std::string		WrongAnimal::getType() const {
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "I am a " << CYAN << this->_type << RESET << " : " << "no sound..." << RED << " /!\\" << RESET << std::endl;
}
