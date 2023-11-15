/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:32:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 23:29:30 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("undetermined_Animal") {
	std::cout << BOLDWHITE << "AAnimal " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type) {
	std::cout << BOLDWHITE << "AAnimal " << BLUE << "parametric constructor " << RESET << "is called for : " << CYAN << _type << RESET << "." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {
	std::cout << BOLDWHITE << "AAnimal " << BLUE << "copy constructor " << RESET << "is called for : " << CYAN << _type << RESET << "." << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << BOLDWHITE << "AAnimal " << RED << "destructor " << RESET << "is called for : " << CYAN << _type << RESET << "." << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &other) {
	_type = other._type;
	std::cout << BOLDWHITE << "AAnimal " << GREEN << "assignment operator " << RESET << "has been called for : " << CYAN << _type << RESET <<"." << std::endl;
	return (*this);
}

const std::string	&AAnimal::getType() const {
	return _type;
}

void	AAnimal::makeSound(void) const {
	std::cout << "I am a " << CYAN << _type << RESET << " : " << "no sound..." << std::endl;
}

const Brain	&AAnimal::getBrain() const {
	static Brain brain;
	std::cout << "This " << CYAN << "undetermined Animal " << RESET << "has no brain!" << std::endl;
	return brain;
}
