/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:40:17 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/23 19:04:03 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "Default_target", 25, 5)
{
	std::cout << UNDER << "PresidentialPardonForm Default Constructor"
		<< RESET << " called with target " << this->getTarget() << "!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << UNDER << "PresidentialPardonForm Parametric Constructor"
		<< RESET << " called with target " << this->getTarget() << "!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	std::cout << UNDER << "PresidentialPardonForm Copy Constructor"
		<< RESET << " called with target " << this->getTarget() << "!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << UNDER << "PresidentialPardonForm Destructor"
		RESET << " called with target " << this->getTarget() << "!" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	std::cout << UNDER << "PresidentialPardonForm Assignment Operator"
		<< RESET " called with target " << this->getTarget() << "!" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::beExecuted(const Bureaucrat &executor) const
{
	std::cout << CYAN << "Under the action of " << executor.getName() << ", "
		<< this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
