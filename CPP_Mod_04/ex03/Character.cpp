/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:44:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/21 18:29:24 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name(noName), _inventaire(new AMateria[4]) {
	std::cout << "Character default constructor called for " << getName() << "." << std::endl;
}

Character::Character( const std::string& name ) : _name(name), _inventaire(new AMateria[4]) {
	std::cout << "Character parametric constructor called for " << getName() << "." << std::endl;
}

Character::Character( const Character& original ) : _name(original.getName() {
	for (int i = 0; i < NB_MATERIA; ++i) {
		delete _inventaire[i];
		_inventaire[i] = new AMateria(original._inventaire[i]);)
	}
	std::cout << "Character copy constructor called for " << getName() << "." << std::endl;
}

Character::~Character( void ) {
	delete [] _inventaire;
	std::cout << "Character destructor called for " << getName() << "." << std::endl;
}

Character& Character::operator=( const Character& original ) {
	_name = original._name;
	for (int i = 0; i < NB_MATERIA; ++i) {
		delete _inventaire[i];
		_inventaire[i] = new AMateria(original._inventaire[i]);)
		}
	std::cout << "Character assignment operator has been called." << std::endl;
	return (*this);
}

std::string const &	Character::getName( void ) const {
	return (_name);
}

void				Character::equip( AMateria* m ) {
	for (int i = 0; i < NB_MATERIA; ++i) {
		if (!_inventaire[i])
			_inventaire[i] = m;
	}
}

void				Character::unequip( int idx ) {
	_inventaire[idx] = NULL;
}

void				Character::use( int idx, ICharacter& target ) {
	_inventaire[idx].use(target);
}
