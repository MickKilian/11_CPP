/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:26:11 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/04/29 02:34:04 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanA {

	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void	attack(void) const;

	private:

		std::string	_name;
		Weapon		&_weapon;
};

#endif // HUMAN_A_H
