/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:13:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 23:28:46 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>
#include "Brain.hpp"

#define RED				"\x1b[31m"
#define GREEN			"\x1b[32m"
#define CYAN			"\x1b[36m"
#define YELLOW			"\x1b[33m"
#define MAGENTA			"\x1b[35m"
#define BOLDMAGENTA		"\x1b[35;1m"
#define BLUE			"\x1b[34m"
#define WHITE			"\x1b[37m"
#define BOLDWHITE		"\x1b[37;1m"
#define RESET			"\x1b[0m"

class AAnimal {
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &other);
		const std::string	&getType() const;
		virtual void		makeSound() const = 0;
		virtual const Brain	&getBrain() const;

	protected:
		AAnimal(const std::string &type);

	private:
		std::string	_type;
};

#endif //AANIMAL
