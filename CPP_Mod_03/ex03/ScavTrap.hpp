/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:30:59 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/11 22:19:30 by mbourgeo         ###   ########.fr       */
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
	void		guardGate() const;
};

std::ostream	&operator<<(std::ostream &o, ScavTrap const &rhs);

#endif // SCAV_TRAP_H
