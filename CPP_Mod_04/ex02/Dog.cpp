/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:26:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 23:30:12 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("dog"), _brain(new Brain()) {
	std::cout << BOLDWHITE << "Dog " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << BOLDWHITE << "Dog " << BLUE << "copy constructor " << RESET << "is called." << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << BOLDWHITE << "Dog " << RED << "destructor " << RESET << "is called." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	AAnimal::operator=(other);
	*_brain = *other._brain;
	std::cout << BOLDWHITE << "Dog " << GREEN << "assignment operator " << RESET << "has been called." << std::endl;
	return (*this);
}

void	Dog::makeSound(void)  const {
	std::cout << "I am a " << CYAN << getType() << RESET << " : " << YELLOW << "Woof Woof!!" << RESET << std::endl;
}

const Brain	&Dog::getBrain() const {
	return *_brain;
}
