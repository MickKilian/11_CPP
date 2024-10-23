/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:25:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/20 21:44:34 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include <stdexcept>
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &);
		virtual ~Intern();
		Intern &operator=(const Intern &);

		AForm	*makeForm(const std::string &, const std::string &) const;

	class UnclassifiedFormException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form does not exist!");
			}
	};

};

#endif // INTERN_H
