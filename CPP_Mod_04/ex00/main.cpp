/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:37:31 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/27 00:42:03 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {
	std::cout << std::endl << WHITE << "***************" << RESET << std::endl;
	std::cout << WHITE << "* FIRST TESTS *" << RESET << std::endl;
	std::cout << WHITE << "***************" << RESET << std::endl;

	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "animal is of type " << CYAN << animal->getType() << RESET << "." <<std::endl;
	std::cout << "dog if of type " << CYAN << dog->getType() << RESET << "." << std::endl;
	std::cout << "cat is of type " <<  CYAN << cat->getType() << RESET << "." << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;
	delete animal;
	delete dog;
	delete cat;

	std::cout << std::endl << WHITE << "****************" << RESET << std::endl;
	std::cout << WHITE << "* SECOND TESTS *" << RESET << std::endl;
	std::cout << WHITE << "****************" << RESET << std::endl;

	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "wrongCat is of type " <<  CYAN << wrongCat->getType() << RESET << "." << std::endl;
	wrongCat->makeSound();
	std::cout << std::endl;
	delete wrongCat;
	std::cout << std::endl;

	return 0;
}
