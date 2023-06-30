/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:55:43 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 17:24:29 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::Harl(std::string filter) {
	_filter = filter;
}

Harl::~Harl() {
}

void	Harl::complain(std::string level) {
	switch (getLevel(level) < getLevel(_filter) ? -1 : getLevel(level)) {
		case 0:
			_display(0);
			break;
		case 1:
			_display(1);
			break;
		case 2:
			_display(2);
			break;
		case 3:
			_display(3);
			break;
		default:
			std::cout << RED << "[ Probably complaining about insignificant problems ]" << RESET << std::endl << std::endl;
	}
}

void	Harl::_display(const int &levelInt) {
	std::cout << YELLOW << "[ " << Harl::allComments[levelInt].str << " ]" << RESET << std::endl;
	(this->*Harl::allComments[levelInt].func)();
}

std::string		Harl::_filter = "DEBUG";

const t_level	Harl::allComments[] = { {"DEBUG", &Harl::_debug},
											{"INFO", &Harl::_info},
											{"WARNING", &Harl::_warning},
											{"ERROR", &Harl::_error},
											{"END", NULL} };

void	Harl::_debug( void ) {
	std::cout << GREEN
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
		<< " I really do !"
		<< RESET << std::endl << std::endl;
}

void	Harl::_info( void ) {
	std::cout << GREEN
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger ! "
		<< "If you did, I wouldn’t be asking for more !"
		<< RESET << std::endl << std::endl;
}

void	Harl::_warning( void ) {
	std::cout << GREEN
		<< "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working here since last month."
		<< RESET << std::endl << std::endl;
}

void	Harl::_error( void ) {
	std::cout << GREEN
		<< "This is unacceptable ! I want to speak to the manager now."
		<< RESET << std::endl << std::endl;

}

int	getLevel(const std::string &level) {
	int	i = 0;

	while (1) {
		if (level == Harl::allComments[i].str && Harl::allComments[i].str != "END") {
			return (i);
		}
		else if (Harl::allComments[i].str == "END")
			return (-1);
		++i;
	}
}
