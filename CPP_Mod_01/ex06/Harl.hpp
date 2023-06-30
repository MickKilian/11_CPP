/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:52:40 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 17:14:16 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

#define RED				"\x1b[31m"
#define GREEN			"\x1b[32m"
#define YELLOW			"\x1b[33m"
#define RESET			"\x1b[0m"

typedef struct s_level	t_level;

class Harl {
	public:

		Harl();
		Harl(std::string filter);
		~Harl();
		void	complain(std::string level);
		static const t_level	allComments[];

	private :

		void					_display(const int &levelInt);
		void					_debug( void );
		void					_info( void );
		void					_warning( void );
		void					_error( void );
		static std::string		_filter;
};

int		getLevel(const std::string &level);

struct	s_level {
	std::string	str;
	void		(Harl::*func)(void);
};

#endif // HARL_H
