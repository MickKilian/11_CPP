/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:26:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 21:11:41 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "dog";
	std::cout << BOLDWHITE << "Dog " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	*this = other;
	std::cout << BOLDWHITE << "Dog " << BLUE << "copy constructor " << RESET << "is called." << std::endl;
}

Dog::~Dog() {
	std::cout << BOLDWHITE << "Dog " << RED << "destructor " << RESET << "is called." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Assignment operator has been called." << std::endl;
	return (*this);
}

void	Dog::makeSound(void)  const {
	std::cout << "I am a " << CYAN << this->_type << RESET << " : " << YELLOW << "Woof Woof!!" << RESET << std::endl;
}
