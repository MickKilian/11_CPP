/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:20:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 21:11:31 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	this->_type = "cat";
	std::cout << BOLDWHITE << "Cat " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	*this = other;
	std::cout << BOLDWHITE << "Cat " << BLUE << "copy constructor " << RESET << "is called." << std::endl;
}

Cat::~Cat(void) {
	std::cout << BOLDWHITE << "Cat " << RED << "destructor " << RESET << "is called." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Assignment operator has been called." << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "I am a " << CYAN << this->_type << RESET << " : " << YELLOW << "Meow!!" << RESET << std::endl;
}