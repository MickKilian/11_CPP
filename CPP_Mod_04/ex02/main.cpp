/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:37:31 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 23:36:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>

int	main(void) {
	std::cout << std::endl << WHITE << "**********************************" << RESET << std::endl;
	std::cout << WHITE << "* FIRST TESTS : ARRAY of ANIMALS *" << RESET << std::endl;
	std::cout << WHITE << "**********************************" << RESET << std::endl << std::endl;
	const int	arraySize = 4;
	AAnimal* animal[arraySize];

	for (int i = 0; i < arraySize; ++i) {
		if (i < arraySize / 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < arraySize; ++i) {
		std::cout << "Animal #" << WHITE << i + 1 << RESET << ", ";
		animal[i]->makeSound();
		std::cout << BOLDWHITE << "You want to know my ideas?" << RESET << std::endl;
		if (animal[i]->getType() != "undeterminded_animal") {
			for (int j = 0; j < NB_IDEAS; ++j)
				animal[i]->getBrain().getIdea(j);
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < arraySize; ++i) {
		delete animal[i];
	}

	std::cout << std::endl << std::endl << WHITE << "*****************************************************" << RESET << std::endl;
	std::cout << WHITE << "* SECOND TESTS : COPY CONSTRUCTORS and ASSIGNEMENTS *" << RESET << std::endl;
	std::cout << WHITE << "*****************************************************" << RESET << std::endl;
	std::cout << std::endl << WHITE << "******************" << RESET << std::endl;
	std::cout << WHITE << "* CHECK WITH DOG *" << RESET << std::endl;
	std::cout << WHITE << "******************" << RESET << std::endl << std::endl;
	Dog	dog;
	Dog	dog_copy(dog);
	Dog dog_new;
	dog_new = dog;
	std::cout << std::endl;
	int ideaId = Random::generate(NB_IDEAS);
	std::cout << "The " << CYAN << "dog" << RESET << "'s      brain is pointing to : " << MAGENTA << &dog.getBrain() << RESET << std::endl;
	std::cout << RESET << "Idea #" << WHITE;
	dog.getBrain().getIdea(ideaId - 1);
	std::cout << "The " << CYAN << "dog_copy" << RESET << "'s brain is pointing to : " << MAGENTA << &dog_copy.getBrain() << RESET << std::endl;
	std::cout << RESET << "Idea #" << WHITE;
	dog_copy.getBrain().getIdea(ideaId - 1);
	std::cout << "The " << CYAN << "dog_new" << RESET << "'s  brain is pointing to : " << MAGENTA << &dog_new.getBrain() << RESET << std::endl;
	std::cout << RESET << "Idea #" << WHITE;
	dog_new.getBrain().getIdea(ideaId - 1);
	std::cout << std::endl << WHITE << "******************" << RESET << std::endl;
	std::cout << WHITE << "* CHECK WITH CAT *" << RESET << std::endl;
	std::cout << WHITE << "******************" << RESET << std::endl << std::endl;
	Cat	cat;
	Cat	cat_copy(cat);
	Cat cat_new;
	cat_new = cat;
	std::cout << std::endl;
	ideaId = Random::generate(NB_IDEAS);
	std::cout << "The " << CYAN << "cat" << RESET << "'s      brain is pointing to : " << MAGENTA << &cat.getBrain() << RESET << std::endl;
	std::cout << RESET << "Idea #" << WHITE;
	cat.getBrain().getIdea(ideaId - 1);
	std::cout << "The " << CYAN << "cat_copy" << RESET << "'s brain is pointing to : " << MAGENTA << &cat_copy.getBrain() << RESET << std::endl;
	std::cout << RESET << "Idea #" << WHITE;
	cat_copy.getBrain().getIdea(ideaId - 1);
	std::cout << "The " << CYAN << "cat_new" << RESET << "'s  brain is pointing to : " << MAGENTA << &cat_new.getBrain() << RESET << std::endl;
	std::cout << RESET << "Idea #" << WHITE;
	cat_new.getBrain().getIdea(ideaId - 1);

	std::cout << std::endl;
	return 0;
}
