/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:52:08 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 17:18:15 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << RED <<"Please enter the minimum tolerated level of complaint as a parameter." << RESET << std::endl;
		return 1;
	}
	else if (getLevel(argv[1]) == -1) {
		std::cout << RED <<"Please enter a valid complaint level." << RESET << std::endl;
		return 1;
	}
	else {
		Harl	comment(argv[1]);
		comment.complain("DEBUG");
		comment.complain("INFO");
		comment.complain("OTHER");
		comment.complain("END");
		comment.complain("WARNING");
		comment.complain("ERROR");
		comment.complain("ERROR");
		comment.complain("WARNING");
		comment.complain("CLAIM");
		comment.complain(argv[1]);
	}
	return 0;
}
