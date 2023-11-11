/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:45:53 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 00:26:35 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
	_name = ClapTrap::_name;
	ClapTrap::_name = _name + "_clap_name";
	_type = "DiamondTrap";
	_healthPoints = FragTrap::_healthPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_damagePoints = FragTrap::_damagePoints;
	std::cout << "DiamondTrap default constructor has been called to create " << _name << "." << std::endl;
}

/*DiamondTrap::DiamondTrap() : ClapTrap("defaultName", 100, 50, 20) {
	std::cout << "DiamondTrap default constructor has been called." << std::endl;
}*/

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	*this = other;
	std::cout << "DiamondTrap copy constructor has been called based on " << other._name << "." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name) {
	ClapTrap::_name = _name + "_clap_name";
	_type = "DiamondTrap";
	_healthPoints = FragTrap::_healthPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_damagePoints = FragTrap::_damagePoints;
	std::cout << "DiamondTrap parametric constructor has been called for " << name << "." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor has been called for " << this->_name << "." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other) {
	this->_name = other._name;
	this->_healthPoints = other._healthPoints;
	this->_energyPoints = other._energyPoints;
	this->_damagePoints = other._damagePoints;
	std::cout << "Assignment operator has been called using " << other._name << "." << std::endl;
	return(*this);
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << GREEN << _type << "'s name is : " << _name;
	std::cout << RESET << std::endl;
	std::cout << GREEN << ClapTrap::_type << "'s name is : " << ClapTrap::_name;
	std::cout << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &o, DiamondTrap const &rhs) {
	o << WHITE << "   " << rhs.getName() << "| " << "healthPoints: " << rhs.getHealth() << ", energyPoints: " << rhs.getEnergy() << ", damagePoints: " << rhs.getDamage() << ".";
	std::cout << RESET;
	return (o);
}

