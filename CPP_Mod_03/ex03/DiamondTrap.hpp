/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:45:57 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/11 23:28:17 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

#define RED				"\x1b[31m"
#define BOLDRED			"\x1b[31;1m"
#define GREEN			"\x1b[32m"
#define BOLDGREEN		"\x1b[32;1m"
#define YELLOW			"\x1b[33m"
#define BLUE			"\x1b[34m"
#define BOLDBLUE		"\x1b[34;1m"
#define MAGENTA			"\x1b[35m"
#define BOLDMAGENTA		"\x1b[35;1m"
#define CYAN			"\x1b[36m"
#define BOLDCYAN		"\x1b[36;1m"
#define WHITE			"\x1b[37m"
#define RESET			"\x1b[0m"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
	DiamondTrap();
	DiamondTrap(std::string);
	//DiamondTrap(std::string, unsigned int, unsigned int, unsigned int);
	DiamondTrap(const DiamondTrap &);
	~DiamondTrap();
	
	DiamondTrap	&operator=(const DiamondTrap &);
	void		attack(const std::string &);
	void		whoAmI(void);

protected:
	std::string		_name;
};

std::ostream	&operator<<(std::ostream &o, DiamondTrap const &clap);

#endif // DIAMOND_TRAP_H
