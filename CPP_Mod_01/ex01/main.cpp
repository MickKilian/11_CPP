#include "Zombie.hpp"

int	main( void ) {
	int	n = 5;
	Zombie*	horde = zombieHorde(n, "tutur");

	for (int i = 0; i < n; ++i) {
		(horde + i)->announce();
	}
	delete [] horde;
	//for (int i = 0; i < n; ++i) {
	//	horde[i].~Zombie();
	//}
	//operator delete(horde);
	return 0;
}
