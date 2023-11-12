/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:20:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 05:17:05 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	//this->_type = "Cat";
	std::cout << "Cat default constructor is called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other) {
	*this = other;
	std::cout << "Cat copy constructor is called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor is called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Assignment operator has been called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "I am a cat and I meow!!!" << std::endl;
}
