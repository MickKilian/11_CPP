#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	std::string	say = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	for (int i = 1; i < argc; ++i)
	{
		say = argv[i];
		for (unsigned long j = 0; j < say.size(); ++j) {
			say[j] = std::toupper(say[j]);
		}
		std::cout << say << std::endl;
	}
	if (argc == 1)
		std::cout << say << std::endl;
	return 0;
}
