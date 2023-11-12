/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:13:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/12 05:17:34 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
	public:
		Animal();
		Animal(const Animal &other);
		~Animal();

		Animal &operator=(const Animal &other);
		std::string		getType() const;
		virtual void	makeSound() const;

	protected:
		std::string	_type;
};

#endif //ANIMAL
