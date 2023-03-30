#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class	Zombie {

	public:

		static void	setHordeName(std::string hordeName);

		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);

	private:

		static std::string	_hordeName;
		static int			_zombieID;

		std::string	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);
Zombie* zombieHorde_2(int N, std::string name);

#endif // ZOMBIE_H
