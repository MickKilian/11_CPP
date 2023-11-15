/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:32:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 23:18:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("undetermined_animal") {
	std::cout << BOLDWHITE << "Animal " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
	std::cout << BOLDWHITE << "Animal " << BLUE << "parametric constructor " << RESET << "is called for : " << CYAN << _type << RESET << "." << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
	std::cout << BOLDWHITE << "Animal " << BLUE << "copy constructor " << RESET << "is called for : " << CYAN << _type << RESET << "." << std::endl;
}

Animal::~Animal() {
	std::cout << BOLDWHITE << "Animal " << RED << "destructor " << RESET << "is called for : " << CYAN << _type << RESET << "." << std::endl;
}

Animal	&Animal::operator=(const Animal &other) {
	_type = other._type;
	std::cout << BOLDWHITE << "Animal " << GREEN << "assignment operator " << RESET << "has been called for : " << CYAN << _type << RESET <<"." << std::endl;
	return (*this);
}

const std::string	&Animal::getType() const {
	return _type;
}

void	Animal::makeSound(void) const {
	std::cout << "I am a " << CYAN << _type << RESET << " : " << "no sound..." << std::endl;
}

const Brain	&Animal::getBrain() const {
	static Brain brain;
	std::cout << "This " << CYAN << "undetermined animal " << RESET << "has no brain!" << std::endl;
	return brain;
}
