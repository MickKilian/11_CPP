#include <sstream>
#include <iostream>
#include <string>

void split(const std::string& str) {

	std::stringstream ss(str);
	std::string       end;
	std::string       word;

	while (ss >> word) {
		std::cout << "word: " << word << std::endl;
		end.append(word + ' ');
	}
	end.erase(end.size() - 1);
	std::cout << "end: " << end << std::endl;

}

int main(int ac, char** av) {

	if (ac == 2) {
		split(av[1]);
	}
	return 0;
}


