/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:13:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 21:44:44 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>

#define RED				"\x1b[31m"
#define CYAN			"\x1b[36m"
#define YELLOW			"\x1b[33m"
#define BLUE			"\x1b[34m"
#define WHITE			"\x1b[37m"
#define BOLDWHITE		"\x1b[37;1m"
#define RESET			"\x1b[0m"

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &other);
		std::string	getType() const;
		void		makeSound() const;

	protected:
		std::string	_type;
};

#endif //WRONG_ANIMAL
