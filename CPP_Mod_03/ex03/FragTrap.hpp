/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:58:00 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/10 22:08:01 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
	public:
		FragTrap();
		FragTrap(const std::string &);
		FragTrap(const FragTrap &);
		~FragTrap();
		
		FragTrap	&operator=(const FragTrap &);
		void		attack(const std::string &);
		void		highFiveGuys() const;

		static const unsigned int	_defaultHealthPoints = 100;
		static const unsigned int	_defaultEnergyPoints = 100;
		static const unsigned int	_defaultDamagePoints = 30;
};

std::ostream	&operator<<(std::ostream &o, FragTrap const &rhs);

#endif // FRAG_TRAP_H
