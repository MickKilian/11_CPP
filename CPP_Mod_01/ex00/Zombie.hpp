/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:26:29 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 12:14:03 by mbourgeo         ###   ########.fr       */
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
		void	announce(void);

	private:
		std::string	_name;
};

#endif // ZOMBIE_H
