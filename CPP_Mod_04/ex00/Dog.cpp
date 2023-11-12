/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:26:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 05:17:13 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	//this->_type = "Dog";
	std::cout << "Dog default constructor is called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other) {
	*this = other;
	std::cout << "Dog copy constructor is called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor is called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Assignment operator has been called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void)  const {
	std::cout << "I am a dog and I bark!!!" << std::endl;
}
