/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:55:43 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/04/30 19:06:29 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

const t_level	Harl::_allComments[] = { {"DEBUG", &Harl::_debug},
											{"INFO", &Harl::_info},
											{"WARNING", &Harl::_warning},
											{"ERROR", &Harl::_error},
											{"END", NULL} };

void	Harl::complain( std::string level ) {
	int		i = 0;

	 while (1) {
		if (Harl::_allComments[i].str != "END" && level == Harl::_allComments[i].str) {
			std::cout << YELLOW << "[ " << Harl::_allComments[i].str << " ]" << RESET << std::endl;
			(this->*Harl::_allComments[i].func)();
			break;
		}
		else if (Harl::_allComments[i].str == "END") {
			std::cout << RED << "[ " << level << " ]" << RESET << std::endl;
			std::cout << "----> Input level is not recognized!!!" << std::endl;
			break;
		}
		++i;
	}
}

void	Harl::_debug( void ) {
	std::cout << GREEN
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
		<< " I really do !"
		<< RESET << std::endl;
}

void	Harl::_info( void ) {
	std::cout << GREEN
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger ! "
		<< "If you did, I wouldn’t be asking for more !"
		<< RESET << std::endl;
}

void	Harl::_warning( void ) {
	std::cout << GREEN
		<< "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working here since last month."
		<< RESET << std::endl;
}

void	Harl::_error( void ) {
	std::cout << GREEN
		<< "This is unacceptable ! I want to speak to the manager now."
		<< RESET << std::endl;

}
