/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:45:53 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 04:00:11 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
	_name = ClapTrap::_name;
	ClapTrap::_name = _name + "_clap_name";
	_type = "DiamondTrap";
	std::cout << "test" << std::endl;
	_healthPoints = FragTrap::_defaultHealthPoints;
	_energyPoints = ScavTrap::_defaultEnergyPoints;
	_damagePoints = FragTrap::_defaultDamagePoints;
	std::cout << "DiamondTrap default constructor has been called to create " << _name << "." << std::endl;
}

/*DiamondTrap::DiamondTrap() : ClapTrap("defaultName", 100, 50, 20) {
	std::cout << "DiamondTrap default constructor has been called." << std::endl;
}*/

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	*this = other;
	std::cout << "DiamondTrap copy constructor has been called based on " << other._name << "." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	std::cout << "test clap_name is " << ClapTrap::_name << std::endl;
	_name = name;
	_type = "DiamondTrap";
	_healthPoints = FragTrap::_defaultHealthPoints;
	_energyPoints = ScavTrap::_defaultEnergyPoints;
	_damagePoints = FragTrap::_defaultDamagePoints;
	std::cout << "DiamondTrap parametric constructor has been called to create " << name << "." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor has been called for " << this->_name << "." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		this->_type = other._type;
		this->_name = other._name;
		this->_healthPoints = other._healthPoints;
		this->_energyPoints = other._energyPoints;
		this->_damagePoints = other._damagePoints;
	}
	std::cout << "Assignment operator has been called with reference : " << other._name << "." << std::endl;
	return(*this);
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const {
	std::cout << GREEN << _type << "'s name is : " << _name;
	std::cout << RESET << std::endl;
	std::cout << GREEN << ClapTrap::_type << "'s name is : " << ClapTrap::_name;
	std::cout << RESET << std::endl;
}

std::string	DiamondTrap::getDiamondName(void) const {
	return (_name);
}

std::ostream	&operator<<(std::ostream &o, DiamondTrap const &rhs) {
	o << WHITE << "   " << rhs.getDiamondName() << "| " << "healthPoints: " << rhs.getHealth() << ", energyPoints: " << rhs.getEnergy() << ", damagePoints: " << rhs.getDamage() << ".";
	std::cout << RESET;
	return (o);
}

