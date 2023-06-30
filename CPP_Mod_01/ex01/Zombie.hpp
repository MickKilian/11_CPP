/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:26:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 14:04:00 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class	Zombie {

	public:

		Zombie();
		Zombie(std::string name);
		~Zombie(void);

		static void	setHordeName(std::string hordeName);
		void		announce(void);

	private:

		static std::string	_hordeName;
		static int			_zombieID;

		std::string	_name;
};

#endif // ZOMBIE_H
