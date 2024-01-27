/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:17:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/26 23:56:28 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria( "ice" ) {
	std::cout << GREEN << "Default constructor" << RESET << " called for" << BOLDCYAN << " ice" << RESET << "." << std::endl;
}

Ice::Ice( const Ice& other ) : AMateria( other ) {
	std::cout << GREEN << "Copy constructor" << RESET << " called for" << BOLDCYAN << " ice" << RESET << "." << std::endl;
}

Ice::~Ice() {
	std::cout << RED << "Destructor" << RESET << " called for" << BOLDCYAN << " ice" << RESET << "." << std::endl;
}

Ice& Ice::operator=( const Ice& other ) {
	(void)other;
	std::cout << GREEN << "Assignment operator" << RESET << " called for" << BOLDCYAN << " ice" << RESET << "." << std::endl;
	return (*this);
}

AMateria*	Ice::clone( void ) const {
	return (new Ice(*this));
}

void		Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << YELLOW << target.getName() << RESET << " *"<< std::endl;
}
