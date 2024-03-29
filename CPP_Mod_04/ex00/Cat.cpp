/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:20:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 19:30:21 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("cat") {
	std::cout << BOLDWHITE << "Cat " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	//*this = other;
	std::cout << BOLDWHITE << "Cat " << BLUE << "copy constructor " << RESET << "is called." << std::endl;
}

Cat::~Cat(void) {
	std::cout << BOLDWHITE << "Cat " << RED << "destructor " << RESET << "is called." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	//if (this != &other)
	//	_type = other._type;
	Animal::operator=(other);
	std::cout << "Assignment operator has been called." << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "I am a " << CYAN << getType() << RESET << " : " << YELLOW << "Meow!!" << RESET << std::endl;
}
