/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:58:00 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 02:01:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
public:
	FragTrap();
	FragTrap(std::string);
	FragTrap(const FragTrap &);
	virtual ~FragTrap();
	
	FragTrap	&operator=(const FragTrap &);
	void		attack(const std::string &);
	void		highFiveGuys() const;

	static const unsigned int	_defaultHealthPoints = 100;
	static const unsigned int	_defaultEnergyPoints = 100;
	static const unsigned int	_defaultDamagePoints = 30;
};

std::ostream	&operator<<(std::ostream &o, FragTrap const &rhs);

#endif // FRAG_TRAP_H
