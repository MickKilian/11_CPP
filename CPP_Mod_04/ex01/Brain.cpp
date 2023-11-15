/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:32:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 16:31:24 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

const std::string characters[10] = {
	"tree", "lion", "bird", "house", "city",
	"sun", "moon", "car", "man", "woman" };
const std::string actions[10] = {
	"eats", "kills", "plays with", "dreams of", "tells a secret to",
	"goes for a ride with", "bakes a cake with", "laughs with", "dreams about", "is secretely in love with" };

typedef unsigned long size_type;

size_type	Random::generate(void) {
	return shared().generate_impl();
}

size_type	Random::generate(size_type max) {
	return shared().generate_impl() % max;
}

Random&		Random::shared(void) {
	static Random instance;
	return instance;
}

size_type	Random::generate_impl(void) {
	return std::rand();
}

Random::Random(void) {
	std::srand(time(NULL) ^ getpid());
}

Brain::Brain() {
	int subjectId;
	int objectId; 
	for (int i = 0; i < 100; ++i) {
		subjectId = Random::generate(10);
		objectId = Random::generate(10); 
		while (objectId == subjectId)
			objectId = Random::generate(10);
		_ideas[i] = "The " + characters[subjectId] + " " + actions[Random::generate(10)] + " the " + characters[objectId];
	}
	std::cout << BOLDWHITE << "Brain " << BLUE << "default constructor " << RESET << "is called." << std::endl;
}

Brain::Brain(const Brain &other) {
	*this = other;
	std::cout << BOLDWHITE << "Brain " << BLUE << "copy constructor " << RESET << "is called." << std::endl;
}

Brain::~Brain() {
	std::cout << BOLDWHITE << "Brain " << RED << "destructor " << RESET << "is called." << std::endl;
}

Brain	&Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	std::cout << BOLDWHITE << "Brain " << GREEN << "assignment operator " << RESET << "has been called." << std::endl;
	return (*this);
}

void	Brain::getIdea(int index) {
	std::cout << index + 1 << ". " << WHITE << this->_ideas[index] << RESET << std::endl;
}