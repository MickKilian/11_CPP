/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:09:56 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/10 00:13:18 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	FragTrap	susan;
	FragTrap	elie("Elie");
	FragTrap	denise(elie);
	FragTrap	simona("Simona");
	FragTrap	eleanore;
	eleanore = simona;
	ClapTrap	didie("Didie");

	// We have 4 FragTrap susan(defaultName), elie(Elie), simona(Simona) and eleanore(Simona).
	// None of them has damagePoints, so they can can attack but will not cause any damage to their opponent.

	FragTrap	simon("Simon"), victor("Victor");
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
