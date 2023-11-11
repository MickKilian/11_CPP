/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:58:00 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/07 20:14:51 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string);
	FragTrap(const FragTrap &);
	virtual ~FragTrap();
	
	FragTrap	&operator=(const FragTrap &);
	void		highFiveGuys() const;
};

std::ostream	&operator<<(std::ostream &o, FragTrap const &rhs);

#endif // FRAG_TRAP_H
