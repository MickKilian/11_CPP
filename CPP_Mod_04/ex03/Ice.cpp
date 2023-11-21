/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:17:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/21 15:42:19 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria( "ice" ) {
	std::cout << "Default consructor called for ice." << std::endl;
}

Ice::Ice( const Ice& original ) : AMateria( original.getType() ) {
	std::cout << "Copy consructor called for ice." << std::endl;
}

Ice::~Ice() {
	std::cout << "Destructor called for ice." << std::endl;
}

Ice& Ice::operator=( const Ice& original ) {
	_type = original._type;
	std::cout << "Assignement operator called for ice." << std::endl;
	return *this;
}

AMateria*	Ice::clone( void ) const {
	return (new Ice());
}

void		Ice::use( ICharacter& target ) {
	std::cout << "Ice :"* shoots an ice bolt at " << target << " *"<< std::endl;
}
