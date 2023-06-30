/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:26:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 14:11:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main( void ) {
	int	n = 5;
	Zombie*	horde = zombieHorde(n, "Tutur");

	for (int i = 0; i < n; ++i) {
		(horde + i)->announce();
	}
	delete [] horde;
	return 0;
}
