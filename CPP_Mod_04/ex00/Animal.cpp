/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:32:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 05:17:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(Animal const &other) {
	*this = other;
	std::cout << "Animal copy constructor is called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor is called" << std::endl;
}

Animal	&Animal::operator=(const Animal &other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Assignment operator has been called" << std::endl;
	return (*this);
}

std::string		Animal::getType() const {
	return (this->_type);
}

void	Animal::makeSound(void) const {
	std::cout << "I am an animal and the sound I amke depends on the type of animal I am" << std::endl;
}
