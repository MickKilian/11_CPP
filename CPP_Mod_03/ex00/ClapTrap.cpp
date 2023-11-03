/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:07:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/10/27 21:13:06 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	_name = clapTrap._name;
	_hitPoints = clapTrap._hitPoints;
	_damagePoints = clapTrap._damagePoints;
	_attackDamage = clapTrap._attackDamage;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor has been called" << std::endl;
}


void	ClapTrap::attack(const std::string& target) {
	if (_energyPoints > 0) {
		--_energyPoints;
		std::cout << _name + " is attacking " + target + " causing " + _attackDamage + " points of damage." << std::endl;
	}
	else {
		std::cout << _name + "has no energy point left." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	int	initialHitPoints = _hitPoints;
	_hitPoints = std::max(0, _hitPoints-amount);
	std::cout << _name + " is taking " + initialHitPoints - _hitPoints + " points of damage." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0) {
		--_energyPoints;
		_hitPoints += amount;
		std::cout << _name + " is regaining " + amount + " hit points." << std::endl;
	}
	else {
		std::cout << _name + " has no energy point to get repaired." << std::endl;
	}
}
