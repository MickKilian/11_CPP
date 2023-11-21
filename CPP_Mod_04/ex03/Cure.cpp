/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:14:42 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/16 01:50:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria( "cure" ) {
	std::cout << "Default consructor called for cure." << std::endl;
}

Cure::Cure( const Cure& original ) : AMateria( original.getType() ) {
	std::cout << "Copy consructor called for cure." << std::endl;
}

Cure::~Cure() {
	std::cout << "Destructor called for cure." << std::endl;
}

Cure& Cure::operator=( const Cure& original ) {
	_type = original._type;
	std::cout << "Assignement operator called for cure." << std::endl;
	return *this;
}

AMateria* Cure::clone( void ) const {
	return (new Cure());
}
