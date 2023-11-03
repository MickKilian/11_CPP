/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:42:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/10/27 21:13:46 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &clapTrap);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amout);

	private:
		std::string		_name;
		int				_hitPoints = 0;
		int				_energyPoints = 10;
		int				_attackDamage = 10;
};

#endif // CLAPTRAP_H
