/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:38:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/26 23:39:18 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	for( int i = 0 ; i < NB_MAX_LEARNED ; i++ )
		_learnedMateria[i] = NULL;
	std::cout << MAGENTA << "MateriaSource" <<  GREEN << " default constructor" << RESET << " called." << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &other ) {
	for (int i = 0; i < NB_MAX_LEARNED; i++) {
		if (other._learnedMateria[i])
			_learnedMateria[i] = other._learnedMateria[i]->clone();
		else
			_learnedMateria[i] = NULL;
	}
	std::cout << MAGENTA << "MateriaSource" <<  GREEN << " copy constructor" << RESET << " called." << std::endl;
}

MateriaSource::~MateriaSource( void ) {
	for (int i = 0; i < NB_MAX_LEARNED; i++) {
		if (_learnedMateria[i])
			delete _learnedMateria[i];
	}
	std::cout << MAGENTA << "MateriaSource" << RED << " destructor" << RESET << " called." << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < NB_MAX_LEARNED; i++) {
			if (other._learnedMateria[i]) {
				delete _learnedMateria[i];
				_learnedMateria[i] = other._learnedMateria[i]->clone();
			}
			else
				_learnedMateria[i] = NULL;
		}
	}
	std::cout << MAGENTA << "MateriaSource" <<  GREEN << " assignment operator" << RESET << " called." << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* aMateria) {
	bool	stored = false;
	int		countSameType = 0;
	for (int i = 0; i < NB_MAX_LEARNED; i++) {
		if (!_learnedMateria[i]) {
			if (countSameType != NB_MAX_LEARNED - 1) {
				_learnedMateria[i] = aMateria;
				stored = true;
				std::cout << "Materia type : " << BOLDCYAN<< aMateria->getType() << RESET << " was just stored in the list of learned Materia." << std::endl;
			}
			else {
				std::cout << "Materia type : " << BOLDCYAN << aMateria->getType() << RESET << " was not stored as no more space is available for this materia type." << std::endl;
				delete aMateria;
			}
			return;
		}
		else if (_learnedMateria[i]->getType() == aMateria->getType())
			countSameType++;
	}
	if (!stored) {
		std::cout << "Materia type : " << BOLDCYAN << aMateria->getType() << RESET << " was not stored as not more space is available." << std::endl;
		delete aMateria;
	}
}

AMateria	*MateriaSource::createMateria( std::string const & type ) {
	for (int i = 0; i < NB_MAX_LEARNED; i++) {
		if (_learnedMateria[i] &&_learnedMateria[i]->getType() == type)
			return (_learnedMateria[i]->clone());
	}
	std::cout << "Materia type : " << BOLDCYAN << type << RESET << " is unknown!" << std::endl;
	return (NULL);
}

const AMateria	*MateriaSource::getLearnedList() const {
	return(_learnedMateria[0]);
}
