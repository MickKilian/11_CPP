/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:20:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/13 02:50:52 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	this->_type = "cat";
	_brain = new Brain();
	std::cout << BOLDWHITE << "Cat " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	*this = other;
	std::cout << BOLDWHITE << "Cat " << BLUE << "copy constructor " << RESET << "is called." << std::endl;
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << BOLDWHITE << "Cat " << RED << "destructor " << RESET << "is called." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		this->_type = other._type;
		this->_brain = new Brain(*other.getBrain());
	}
	std::cout << BOLDWHITE << "Cat " << GREEN << "assignment operator " << RESET << "has been called." << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "I am a " << CYAN << this->_type << RESET << " : " << YELLOW << "Meow!!" << RESET << std::endl;
}

Brain	*Cat::getBrain() const {
	return (this->_brain);
}
