/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:44:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/27 00:29:43 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("noName") {
	for (int i = 0; i < NB_MAX_MATERIA; ++i) {
		_inventory[i] = NULL;
	}
	std::cout << YELLOW << "Character" << GREEN << " default constructor" << RESET << " called for " << YELLOW << getName() << RESET << "." << std::endl;
}

Character::Character( const std::string &name ) : _name(name) {
	for (int i = 0; i < NB_MAX_MATERIA; ++i) {
		_inventory[i] = NULL;
	}
	std::cout << YELLOW << "Character" << GREEN << " parametric constructor" << RESET << " called for " << YELLOW << getName() << "." << RESET << std::endl;
}

Character::Character( const Character &other ) : _name(other.getName()) {
	for (int i = 0; i <  NB_MAX_MATERIA; ++i) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << YELLOW << "Character" << GREEN << " copy constructor" << RESET << " called for " << YELLOW << getName() << RESET << "." << std::endl;
}

Character::~Character( void ) {
	for (int i = 0; i < NB_MAX_MATERIA; ++i) {
		if (_inventory[i]) { 
			delete _inventory[i];
		}
	}
	std::cout << YELLOW << "Character" << RED << " destructor" << RESET << " called for " << YELLOW << getName() << RESET << "." << std::endl;
}

Character& Character::operator=( const Character& other ) {
	_name = other._name;
	if (this != &other) {
		for (int i = 0; i <  NB_MAX_MATERIA; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = other._inventory[i]->clone();
			}
			else
				_inventory[i] = NULL;
		}
	}
	std::cout << YELLOW << "Character" << GREEN << " assignment operator" << RESET << " called." << std::endl;
	return (*this);
}

std::string const &	Character::getName( void ) const {
	return (_name);
}

void				Character::equip( AMateria* m ) {
	for (int i = 0; i <  NB_MAX_MATERIA; ++i) {
		if (_inventory[i] == m) {
			std::cout << YELLOW << this->getName() << RESET << " already has this materia." << std::endl;
			return;
		}
	}
	for (int i = 0; i <  NB_MAX_MATERIA; ++i) {
		if (not _inventory[i]) {
			std::cout << YELLOW << this->getName() << RESET << "'s inventory[" << i << "]" << " filled with materia " << BOLDCYAN << m->getType() << RESET << "." << std::endl;
			_inventory[i] = m;
			return;
		}
	}
	std::cout << YELLOW << this->getName() << RESET << "'s inventory is full ." << std::endl;
	delete m;
}

void				Character::unequip( int idx ) {
	if (_inventory[idx])
	{
		std::cout << "Inventory[" << idx << "] of type " << BOLDCYAN << _inventory[idx]->getType() << RESET << " was just trown onto the floor." << std::endl;
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
	else
		std::cout << "There is no materia in Inventory[" << idx << "]." << std::endl;
}

void				Character::use( int idx, ICharacter& target ) {
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "There is no materia in Inventory[" << idx << "]." << std::endl;
}
