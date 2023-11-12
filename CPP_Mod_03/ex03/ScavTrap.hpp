/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:30:59 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 02:04:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(const ScavTrap &);
	virtual ~ScavTrap();
	
	ScavTrap	&operator=(const ScavTrap &);
	void		attack(const std::string &);
	void		guardGate() const;

	static const unsigned int	_defaultHealthPoints = 100;
	static const unsigned int	_defaultEnergyPoints = 50;
	static const unsigned int	_defaultDamagePoints = 20;
};

std::ostream	&operator<<(std::ostream &o, ScavTrap const &rhs);

#endif // SCAV_TRAP_H
