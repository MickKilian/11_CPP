#include "Megaphone.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	Megaphone voice;
	for (int i = 1; i < argc; ++i)
	{
		//std::string arg(argv[1]);
		//Megaphone voice(arg);
		voice.inputMessage(argv[i]);
		voice.sayMessage();
	}
	if (argc == 1)
		voice.sayMessage();
	return 0;
}
