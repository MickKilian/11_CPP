/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:30:24 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/10 00:18:50 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap", "defaultName", 100, 50, 20) {
	std::cout << "ScavTrap default constructor has been called for " << _name << "." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor has been called based on " << other._name << "." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap("ScavTrap", name, 100, 50, 20) {
	std::cout << "ScavTrap parametric constructor has been called for " << name << "." << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor has been called for " << this->_name << "." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "Assignment operator has been called based on " << other._name << "." << std::endl;
	return(*this);
}

void	ScavTrap::attack(const std::string &target) {
	if (_healthPoints == 0) {
		std::cout << RED << "ScavTrap" << " " << _name + " tried to attack but is already dead." << std::endl;
		std::cout << RESET;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << RED << "ScavTrap" << " " << _name + " tried to attack but has no more energy." << std::endl;
		std::cout << RESET;
		return ;
	}
	--_energyPoints;
	if (_damagePoints == 0) {
		std::cout << RED << "ScavTrap" << " " << _name + " is attacking but has no damage points." << std::endl;
		std::cout << RESET;
		return ;
	}
	else {
		std::cout << BOLDRED << "ScavTrap" << " " << _name << " is attacking " << target << " causing " << _damagePoints << " points of damage." << std::endl;
		std::cout << RESET;
	}
}

void	ScavTrap::guardGate() const {
	std::cout << GREEN << _type << " " << _name << " is now keeping the Gate." << std::endl;
	std::cout << RESET;
}

std::ostream	&operator<<(std::ostream &o, ScavTrap const &rhs) {
	o << WHITE << "   " << rhs.getName() << "| " << "healthPoints: " << rhs.getHealth() << ", energyPoints: " << rhs.getEnergy() << ", damagePoints: " << rhs.getDamage() << ".";
	std::cout << RESET;
	return (o);
}
