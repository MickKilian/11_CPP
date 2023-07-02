/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:26:11 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/07/02 19:13:39 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
}

HumanB::~HumanB(void) {
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const {
	if (!this->_weapon)
		std::cout << this->_name << " does not have a weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << (*_weapon).getType() << std::endl;
	return ;
}
