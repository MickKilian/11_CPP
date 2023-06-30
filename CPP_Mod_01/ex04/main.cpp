/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:01:42 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 15:22:58 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "StreamEditor.hpp"

# define RED			"\x1b[31;1m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define BOLDMAGENTA	"\x1b[35;1m"
# define CYAN			"\x1b[36m"
# define RESET			"\x1b[0m"

int	main(int argc, char **argv) {
	int	ret = -1;
	if (argc != 4) {
		std::cout << "Please enter ./mySed followed by 3 parameters (string) : "
			<< "[filename] in which [toDelete] will be replaced by [toInsert]." << std::endl;
		return 1;
	}
	StreamEditor sed(argv[1], argv[2], argv[3]);
	ret = sed.execute();
	if (ret == -1) {
		std::cout << RED << "There was an error opening the file!" << RESET << std::endl; 
		return 1;
	}
	else if (ret == 0) {
		std::cout << BLUE << "String was not found in file!" << RESET << std::endl; 
		return 1;
	}
	else {
		std::cout << GREEN << "String was replaced "
			<< MAGENTA << ret
			<< GREEN << " times in file!" << RESET << std::endl; 
		return 0;
	}
	return 0;
}
