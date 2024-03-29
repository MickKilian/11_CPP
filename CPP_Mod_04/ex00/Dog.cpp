/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:20:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 19:29:59 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("dog") {
	std::cout << BOLDWHITE << "Dog " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	//*this = other;
	std::cout << BOLDWHITE << "Dog " << BLUE << "copy constructor " << RESET << "is called." << std::endl;
}

Dog::~Dog(void) {
	std::cout << BOLDWHITE << "Dog " << RED << "destructor " << RESET << "is called." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	//if (this != &other)
	//	_type = other._type;
	Animal::operator=(other);
	std::cout << "Assignment operator has been called." << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "I am a " << CYAN << getType() << RESET << " : " << YELLOW << "Woof Woof !!" << RESET << std::endl;
}
