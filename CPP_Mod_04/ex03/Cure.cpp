/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:14:42 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/26 23:56:43 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria( "cure" ) {
	std::cout << GREEN << "Default constructor" << RESET << " called for" << BOLDCYAN << " cure" << RESET << "." << std::endl;
}

Cure::Cure( const Cure& other ) : AMateria( other ) {
	std::cout << GREEN << "Copy constructor" << RESET << " called for" << BOLDCYAN << " cure" << RESET << "." << std::endl;
}

Cure::~Cure() {
	std::cout << RED << "Destructor" << RESET << " called for" << BOLDCYAN << " cure" << RESET << "." << std::endl;
}

Cure& Cure::operator=( const Cure& other ) {
	(void)other;
	std::cout << GREEN << "Assginment operator" << RESET << " called for" << BOLDCYAN << " cure" << RESET << "." << std::endl;
	return (*this);
}

AMateria*	Cure::clone( void ) const {
	return (new Cure(*this));
}

void		Cure::use( ICharacter& target ) {
	std::cout << "* Heals " << YELLOW << target.getName() << RESET << "'s wounds *" << std::endl;
}
