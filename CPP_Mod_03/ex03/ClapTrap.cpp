/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:07:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/10 03:26:41 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _type("ClapTrap"), _name("defaultName"), _healthPoints(10), _energyPoints(10), _damagePoints(0) {
	std::cout << "ClapTrap default constructor has been called to create " << _name << "." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
	_type(other._type) ,
	_name(other._name) ,
	_healthPoints(other._healthPoints),
	_energyPoints(other._energyPoints),
	_damagePoints(other._damagePoints) {
	std::cout << "ClapTrap copy constructor has been called based on " << other._name << "." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _type("ClapTrap"), _name(name), _healthPoints(10), _energyPoints(10), _damagePoints(0) {
	std::cout << "ClapTrap parametric constructor has been called to create " << name << "." << std::endl;
}

ClapTrap::ClapTrap(const std::string& type, const std::string& name, unsigned int healthPoints, unsigned int energyPoints, unsigned int damagePoints) :
	_type(type),
	_name(name),
	_healthPoints(healthPoints),
	_energyPoints(energyPoints),
	_damagePoints(damagePoints) {
	std::cout << "ClapTrap parametric constructor has been called to create " << name << "." << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor has been called for " << this->_name << "." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_type = other._type;
		this->_name = other._name;
		this->_healthPoints = other._healthPoints;
		this->_energyPoints = other._energyPoints;
		this->_damagePoints = other._damagePoints;
	}
	std::cout << "ClapTrap assignment operator has been called based on " << other._name << "." << std::endl;
	return(*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (_healthPoints == 0) {
		std::cout << RED << "ClaptTrap " << _name + " tried to attack but is already dead." << std::endl;
		std::cout << RESET;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << RED << "ClapTrap " << _name + " tried to attack but has no more energy." << std::endl;
		std::cout << RESET;
		return ;
	}
	--_energyPoints;
	if (_damagePoints == 0) {
		std::cout << RED << "ClapTrap " << _name + " is attacking but has no damage points." << std::endl;
		std::cout << RESET;
		return ;
	}
	else {
		std::cout << BOLDRED << "ClapTrap " << _name << " is attacking " << target << " causing " << _damagePoints << " points of damage." << std::endl;
		std::cout << RESET;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	unsigned int	initialHealthPoints = _healthPoints;

	if (initialHealthPoints == 0) {
		std::cout << BLUE << "ClapTrap " << _name << " is attacked but is already dead." << std::endl;
		std::cout << RESET;
	}
	else {
		_healthPoints = _healthPoints > amount ? _healthPoints - amount : 0;
		std::cout << BOLDBLUE << "ClapTrap " << _name << " is taking " << initialHealthPoints - _healthPoints << " points of damage";
		if (!_healthPoints)
			std::cout << BOLDBLUE << " and just died. That's sooooo sad!!!" << std::endl;
		else
			std::cout << BOLDBLUE << "." << std::endl;
		std::cout << RESET;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0) {
		--_energyPoints;
		_healthPoints += amount;
		std::cout << GREEN << "ClapTrap " << _name << " is regaining " << amount << " health points." << std::endl;
		std::cout << RESET;
	}
	else {
		std::cout << RED << "ClapTrap " << _name << " tried to be repaired but has no more energy points." << std::endl;
		std::cout << RESET;
	}
}

const std::string	&ClapTrap::getName() const {
	return (this->_name);
}

unsigned int	ClapTrap::getHealth() const {
	return (this->_healthPoints);
}

unsigned int	ClapTrap::getEnergy() const {
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getDamage() const {
	return (this->_damagePoints);
}

std::ostream	&operator<<(std::ostream &o, ClapTrap const &rhs) {
	o << WHITE << "   " << rhs.getName() << "| " << "healthPoints: " << rhs.getHealth() << ", energyPoints: " << rhs.getEnergy() << ", damagePoints: " << rhs.getDamage() << ".";
	std::cout << RESET;
	return (o);
}
