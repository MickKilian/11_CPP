/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:37:29 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/21 17:39:18 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << UNDER << "Intern Default Constructor" << RESET << " called." << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void) other;
	std::cout << UNDER << "Intern Copy Constructor" << RESET << " called." << std::endl;
}

Intern::~Intern()
{
	std::cout << UNDER << "Intern Destructor Constructor" << RESET << " called." << std::endl;
}

Intern	&Intern::operator=(const Intern &other)
{
	(void) other;
	std::cout << UNDER << "Intern Assignment Operator" << RESET << " called." << std::endl;
	return (*this);
}

static AForm	*makeShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*makeRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makePresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &formToBeCreated, const std::string &targetForForm) const
{
	AForm *(*all_form_functions[])(const std::string &target) = {&makeShrubberyForm, &makeRobotomyForm, &makePresidentialForm};
	std::string	formNames[] = {"Shrubbery creation", "Robotomy request", "Presidential pardon"};
	AForm *temp;

	for (int i = 0; i < 3; ++i)
	{
		if (formNames[i] == formToBeCreated)
		{
			temp = all_form_functions[i](targetForForm);
			std::cout << CYAN << "Intern created " << formToBeCreated << " on target " << targetForForm << "." << RESET << std::endl;
			return (temp);
		}
	}
	throw Intern::UnclassifiedFormException();
	return NULL;
}
