/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:54:56 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 03:59:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_type = "FragTrap";
	_healthPoints = 100;
	_energyPoints = 100;
	_damagePoints = 30;
	std::cout << "FragTrap default constructor has been called." << std::endl;
}

/*FragTrap::FragTrap() : ClapTrap("defaultName", 100, 50, 20) {
	std::cout << "FragTrap default constructor has been called." << std::endl;
}*/

FragTrap::FragTrap(const FragTrap &other) {
	*this = other;
	std::cout << "FragTrap copy constructor has been called based on " << other._name << "." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_type = "FragTrap";
	_healthPoints = 100;
	_energyPoints = 100;
	_damagePoints = 30;
	std::cout << "FragTrap parametric constructor has been called for " << name << "." << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor has been called for " << this->_name << "." << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		this->_type = other._type;
		this->_name = other._name;
		this->_healthPoints = other._healthPoints;
		this->_energyPoints = other._energyPoints;
		this->_damagePoints = other._damagePoints;
	}
	std::cout << "Assignment operator has been called using " << other._name << "." << std::endl;
	return(*this);
}

void	FragTrap::attack(const std::string &target) {
	if (_healthPoints == 0) {
		std::cout << RED << "FragTrap" << " " << _name + " tried to attack but is already dead." << std::endl;
		std::cout << RESET;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << RED << "FragTrap" << " " << _name + " tried to attack but has no more energy." << std::endl;
		std::cout << RESET;
		return ;
	}
	--_energyPoints;
	if (_damagePoints == 0) {
		std::cout << RED << "FragTrap" << " " << _name + " is attacking but has no damage points." << std::endl;
		std::cout << RESET;
		return ;
	}
	else {
		std::cout << BOLDRED << "FragTrap" << " " << _name << " is attacking " << target << " causing " << _damagePoints << " points of damage." << std::endl;
		std::cout << RESET;
	}
}

void	FragTrap::highFiveGuys() const {
	std::cout << GREEN << _type << " " << _name << " is yelling : High Five Guys!!!" << std::endl;
	std::cout << RESET;
}

std::ostream	&operator<<(std::ostream &o, FragTrap const &rhs) {
	o << WHITE << "   " << rhs.getName() << "| " << "healthPoints: " << rhs.getHealth() << ", energyPoints: " << rhs.getEnergy() << ", damagePoints: " << rhs.getDamage() << ".";
	std::cout << RESET;
	return (o);
}
