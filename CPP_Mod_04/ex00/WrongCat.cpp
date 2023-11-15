/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:20:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 18:49:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("cat") {
	std::cout << BOLDWHITE << "WrongCat " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << BOLDWHITE << "WrongCat " << BLUE << "copy constructor " << RESET << "is called." << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << BOLDWHITE << "WrongCat " << RED << "destructor " << RESET << "is called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	//if (this != &other)
	//	this->_type = other._type;
	_type = other._type;
	std::cout << "Assignment operator has been called." << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "I am a " << CYAN << this->_type << RESET << " : " << YELLOW << "Meow!!" << RESET << std::endl;
}
