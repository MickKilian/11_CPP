/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:38:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/21 18:49:18 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource( const std::string& original ) {
	std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource::~MateriaSource( void ) {
	std::cout << "MateriaSource destructor called." << std::endl;
}

MateriaSource& MateriaSource::operator=( const std::string& original )

void		MateriaSource::learnMateria( AMateria* ) {
	AMateria* _newMateria(*AMateria);
}

AMateria*	MateriaSource::createMateria( std::string const & type ) {
	this = new AMateria( type );
	return (this);
}
