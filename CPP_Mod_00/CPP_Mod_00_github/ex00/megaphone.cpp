#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	int			i;
	int			j;
	int			k;
	std::string	say;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	i = 1;
	while (i < argc)
	{
		say = argv[i];
		j = 0;
		while (say[j] == 32)
			say.erase(0, 1);
		while (say[j]) {
			k = j;
			while (say[k] && say[k] == 32)
				k++;
			if (!say[k]) {
				say.erase(j, k);
				break;
			}
			say[j] = std::toupper(say[j]);
			j++;
		}
		std::cout << say;
		i++;
		if (say[0] && i < argc)
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
