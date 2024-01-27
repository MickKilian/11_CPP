/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:32:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/26 21:46:43 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type( "unspecified ") {
	std::cout << CYAN << "AMateria" <<  GREEN << " default constructor" << RESET << " called for " << BOLDCYAN << _type << RESET << "." << std::endl;
}

AMateria::AMateria( const std::string& type ) : _type(type) {
	std::cout << CYAN << "AMateria" <<  GREEN << " parametric constructor" << RESET << " called for " << BOLDCYAN << _type << RESET << "." << std::endl;
}

AMateria::AMateria( const AMateria& other) : _type(other._type) {
	std::cout << CYAN << "AMateria" << GREEN << " copy constructor" << RESET << " called for " << BOLDCYAN << other._type << RESET << "." << std::endl;
}

AMateria::~AMateria( void ) {
	std::cout << CYAN << "AMateria" << RED << " destructor" << RESET << " called for " << BOLDCYAN << _type << RESET << "." << std::endl;
}

AMateria	&AMateria::operator=( const AMateria& other ) {
	(void)other;
	std::cout << CYAN << "AMateria" <<  GREEN << " assignment operator" << RESET << " called for " << BOLDCYAN << other._type << RESET << "." << std::endl;
	return (*this);
}

std::string const	&AMateria::getType( void ) const {

	return (_type);
}

void	AMateria::use( ICharacter &user )
{
	(void)user;
}
