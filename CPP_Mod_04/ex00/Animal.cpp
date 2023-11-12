/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:32:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 21:02:53 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("undetermined_animal") {
	std::cout << BOLDWHITE << "Animal " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
	std::cout << BOLDWHITE << "Animal " << BLUE << "copy constructor " << RESET << "is called for : " << CYAN << this->_type << RESET << "." << std::endl;
}

Animal::~Animal() {
	std::cout << BOLDWHITE << "Animal " << RED << "destructor " << RESET << "is called for : " << CYAN << this->_type << RESET << "." << std::endl;
}

Animal	&Animal::operator=(const Animal &other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Assignment operator has been called for : " << CYAN << this->_type << RESET <<"." << std::endl;
	return (*this);
}

std::string		Animal::getType() const {
	return (this->_type);
}

void	Animal::makeSound(void) const {
	std::cout << "I am a " << CYAN << this->_type << RESET << " : " << "no sound..." << std::endl;
}
