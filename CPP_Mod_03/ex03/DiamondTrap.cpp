/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:45:53 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/10 04:01:17 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
		ClapTrap(
				"DiamondTrap",
				"default_clap_name",
				FragTrap::_defaultHealthPoints,
				ScavTrap::_defaultEnergyPoints,
				FragTrap::_defaultDamagePoints),
		FragTrap("defaultName"),
		ScavTrap("defaultName"),
		_name("defaultName") {
	std::cout << "DiamondTrap default constructor has been called to create " << _name << "." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
	std::cout << "DiamondTrap copy constructor has been called based on " << other._name << "." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) :
		ClapTrap(
				"DiamondTrap",
				name + "_clap_name",
				FragTrap::_defaultHealthPoints,
				ScavTrap::_defaultEnergyPoints,
				FragTrap::_defaultDamagePoints),
		FragTrap(name),
		ScavTrap(name),
		_name(name) {
	std::cout << "DiamondTrap parametric constructor has been called to create " << name << "." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor has been called for " << this->_name << "." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	std::cout << "Assignment operator has been called based on : " << other._name << "." << std::endl;
	return(*this);
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const {
	std::cout << GREEN << "DiamondTrap's name is : " << _name;
	std::cout << RESET << std::endl;
	std::cout << GREEN << "ClapTrap's name is : " << ClapTrap::_name;
	std::cout << RESET << std::endl;
}

const std::string	&DiamondTrap::getDiamondName(void) const {
	return (_name);
}

std::ostream	&operator<<(std::ostream &o, DiamondTrap const &rhs) {
	o << WHITE << "   " << rhs.getDiamondName() << "| " << "healthPoints: " << rhs.getHealth() << ", energyPoints: " << rhs.getEnergy() << ", damagePoints: " << rhs.getDamage() << ".";
	std::cout << RESET;
	return (o);
}
