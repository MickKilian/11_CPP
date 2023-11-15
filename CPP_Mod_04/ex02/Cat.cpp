/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:20:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 23:30:06 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("cat"), _brain(new Brain()) {
	std::cout << BOLDWHITE << "Cat " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << BOLDWHITE << "Cat " << BLUE << "copy constructor " << RESET << "is called." << std::endl;
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << BOLDWHITE << "Cat " << RED << "destructor " << RESET << "is called." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	AAnimal::operator=(other);
	*_brain = *other._brain;
	std::cout << BOLDWHITE << "Cat " << GREEN << "assignment operator " << RESET << "has been called." << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "I am a " << CYAN << getType() << RESET << " : " << YELLOW << "Meow!!" << RESET << std::endl;
}

const Brain	&Cat::getBrain() const {
	return *_brain;
}
