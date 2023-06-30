/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:26:11 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 14:49:27 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class	Weapon {

	public:

		Weapon(std::string type);
		~Weapon(void);
		std::string const &	getType(void) const;
		void				setType(const std::string &type);

	private:

		std::string	_type;
};

#endif // WEAPON_H
