/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:56:17 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/27 00:30:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main(void) {
	AMateria		*item1, *item2, *item3;
	MateriaSource	*materialList;
	MateriaSource	*materialList2;
	MateriaSource	*materialList2Cpy;
	Character		*simon, *simonCopy, *betty;

	std::cout << std::endl << BOLDBLUE << "*** BASIC TESTS ***" << RESET << std::endl;
	materialList = new MateriaSource();
	materialList->learnMateria( new Cure() );
	materialList->learnMateria( new Cure() );
	materialList->learnMateria( new Cure() );
	materialList->learnMateria( new Cure() );
	materialList->learnMateria( new Ice() );
	materialList->learnMateria( new Ice() );
	simon = new Character( "Simon" );
	item1 = materialList->createMateria( "ice" );
	simon->equip( item1 );
	item1 = materialList->createMateria( "cure" );
	simon->equip( item1 );

	std::cout << std::endl << BOLDBLUE << "*** DEEP COPIES TESTS FOR MATERIA ***" << RESET << std::endl;
	materialList2 = new MateriaSource();
	materialList2->learnMateria( new Cure() );
	materialList2->learnMateria( new Ice() );
	materialList2Cpy = new MateriaSource( *materialList2 );
	std::cout << MAGENTA << "materialList2" << RESET << " learning List pointer is " << materialList2->getLearnedList() << " while its copy pointer is " << materialList2Cpy->getLearnedList() << std::endl;
	delete materialList2;
	delete materialList2Cpy;

	std::cout << std::endl << BOLDBLUE << "*** EQUIP/UNEQUIP TESTS ***" << RESET << std::endl;
	item1 = materialList->createMateria( "ice" );
	item2 = materialList->createMateria( "cure" );
	item3 = materialList->createMateria( "cure" );
	simon->equip( item1 );
	simon->equip( item1 );
	simon->equip( item2 );
	simon->equip( item1 );
	simon->equip( item3 );
	simon->unequip( 0 );
	simon->unequip( 0 );
	simon->unequip( 3 );

	std::cout << std::endl << BOLDBLUE << "*** DEEP COPY TESTS FOR CHARACTERS ***" << RESET << std::endl;
	betty = new Character( "Betty" );
	simonCopy = new Character( *simon );
	delete simon;
	simonCopy->use( 0, *betty );
	simonCopy->use( 1, *betty );
	simonCopy->use( 2, *betty );

	std::cout << std::endl << BOLDBLUE << "*** NON-EXISTING MATERIA TESTS ***" << RESET << std::endl;
	item1 = materialList->createMateria( "diamond" );
	simonCopy->use( 3, *betty );

	std::cout << std::endl << BOLDBLUE << "*** DELETE OBJECTS ***" << RESET << std::endl;
	delete betty;
	delete simonCopy;
	delete materialList;
}
