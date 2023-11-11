/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:09:56 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/11 22:31:04 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap	susan;
	DiamondTrap	elie("Elie");
	DiamondTrap	denise(elie);
	DiamondTrap	simona("Simona");
	DiamondTrap	eleanore = simona;
	ClapTrap	didie("Didie");

	// We have 4 DiamondTrap susan(defaultName), elie(Elie), simona(Simona) and eleanore(Simona).
	// None of them has damagePoints, so they can can attack but will not cause any damage to their opponent.

	DiamondTrap	simon("Simon"), victor("Victor");
	// We will use Simon and Victor to test our functions

	std::cout << std::endl;
	//

	std::cout << simon << std::endl;
	std::cout << victor << std::endl;

	// let's test function beRepaired while Simon still has energy points
	simon.beRepaired(10);
	std::cout << simon << std::endl;

	// let's make 10 succesive attacks from simon on victor
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

	simon.highFiveGuys();

	//
	std::cout << std::endl;
}
