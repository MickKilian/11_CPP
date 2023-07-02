/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:26:11 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/07/02 19:14:00 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
#define HUMAN_B_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanB {

	public:

		HumanB(std::string);
		~HumanB(void);
		void	setWeapon(Weapon &eeapon);
		void	attack(void) const;

	private:

		std::string	_name;
		Weapon		*_weapon;
};

#endif // HUMAN_B_H
