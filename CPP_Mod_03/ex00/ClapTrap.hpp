/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:42:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/10 00:39:28 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

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

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const std::string &);
		ClapTrap(const ClapTrap &);
		~ClapTrap();
		
		ClapTrap	&operator=(const ClapTrap &);
		void		attack(const std::string &);
		void		takeDamage(unsigned int);
		void		beRepaired(unsigned int);
	
		const std::string	&getName() const;
		unsigned int		getHealth() const;
		unsigned int		getEnergy() const;
		unsigned int		getDamage() const;
	
	private:
		std::string		_name;
		unsigned int	_healthPoints;
		unsigned int	_energyPoints;
		unsigned int	_damagePoints;
};

std::ostream	&operator<<(std::ostream &o, ClapTrap const &scav);

#endif // CLAP_TRAP_H
