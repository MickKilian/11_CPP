#include "Zombie.hpp"

int	main() {
	Zombie*	clara = newZombie("Clara");

	clara->announce();
	delete clara;
	randomChump("Bob");
	return 0;
}
