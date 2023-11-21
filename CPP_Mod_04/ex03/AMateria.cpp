/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:32:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/16 01:30:28 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type( "unspecified ") {
	std::cout << "AMateria default construcor called for " << _type << "." << std::endl;
}

AMateria::AMateria( const std::string& type ) : _type( type ) {
	std::cout << "AMateria parametric construcor called for " << _type << "." << std::endl;
}

AMateria::AMateria( const AMateria& original) : _type( original._type ) {
	std::cout << "AMateria copy construcor called for " << original._type << "." << std::endl;
}

AMateria::~AMateria( void ) {
	std::cout << "AMateria destructor called for " << _type << "." << std::endl;
}

AMateria& AMateria::operator=( const AMateria& original ) {
	_type = original._type;
	std::cout << "AMateria assignement operator called for " << original._type << "." << std::endl;
	return *this;
}

std::string const &	AMateria::getType( void ) const {
	return _type;
}
