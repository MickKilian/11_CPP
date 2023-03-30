#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {

	Zombie::setHordeName(name);
	return (new Zombie[n]);
}

Zombie* zombieHorde_2(int n, std::string name) {

	Zombie* ptr = (Zombie*)operator new(n * sizeof(Zombie));

	for (int i = 0; i < n; ++i) {
		new(ptr + i) Zombie(name);
	}

	return ptr;
}
