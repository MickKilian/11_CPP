/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:26:47 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 14:15:56 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <string>
#include <iostream>
#include <sstream>

Zombie::Zombie() {

	++_zombieID;
	std::stringstream ss;
	ss << _zombieID;
	_name = _hordeName + "_" + ss.str();
	std::cout << _name << " is born" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << _name << " is born" << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " is dead" << std::endl;
}

void	Zombie::setHordeName(std::string hordeName) {
	_hordeName = hordeName;
}

std::string	Zombie::_hordeName = "Isaak";
int Zombie::_zombieID = 0;

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
