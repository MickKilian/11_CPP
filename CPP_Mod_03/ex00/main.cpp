/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:48:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/09 23:52:23 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <stdio.h>

int	main(void) {
	ClapTrap	susan;
	ClapTrap	elie("Elie");
	ClapTrap	denise(elie);
	ClapTrap	simona("Simona");
	ClapTrap	celine = elie;
	ClapTrap	eleanore;
	eleanore = simona;

	// We have 4 ClapTrap susan(defaultName), elie(Elie), simona(Simona) and eleanore(Simona).
	// None of them has damagePoints, so they can can attack but will not cause any damage to their opponent.

	ClapTrap	simon("Simon"), victor("Victor");
	// We will use Simon and Victor to test our functions

	std::cout << std::endl;
	//

	std::cout << simon << std::endl;
	std::cout << victor << std::endl;

	// let's test function beRepaired while Simon still has energy points
	simon.beRepaired(10);
	std::cout << simon << std::endl;

	// let's make 10 successive attacks from simon on victor
	for (int i = 0; i < 11; i++) {
		if  (victor.getEnergy() > 0 && simon.getDamage() > 0) {
			simon.attack("Victor");
			victor.takeDamage(simon.getDamage());
		}
		else
			simon.attack("Victor");
		std::cout << simon << std::endl;
		std::cout << victor << std::endl;
	}

	simon.beRepaired(10);
	std::cout << simon << std::endl;

	//
	std::cout << std::endl;
}
