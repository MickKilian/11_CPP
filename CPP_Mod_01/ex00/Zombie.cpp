#include "Zombie.hpp"

#include <string>
#include <iostream>

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << this->_name << " is born" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->_name << " is dead" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

Zombie*	newZombie(std::string name) {
	Zombie*	newZombie = new Zombie(name);

	return (newZombie);
}

void	randomChump(std::string name) {
	Zombie	zombie(name);

	zombie.announce();
}
