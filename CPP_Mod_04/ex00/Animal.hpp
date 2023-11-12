/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:13:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 21:02:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

#define RED				"\x1b[31m"
#define CYAN			"\x1b[36m"
#define YELLOW			"\x1b[33m"
#define BLUE			"\x1b[34m"
#define WHITE			"\x1b[37m"
#define BOLDWHITE		"\x1b[37;1m"
#define RESET			"\x1b[0m"

class Animal {
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();
		Animal &operator=(const Animal &other);
		std::string		getType() const;
		virtual void	makeSound() const;

	protected:
		std::string	_type;
};

#endif //ANIMAL
