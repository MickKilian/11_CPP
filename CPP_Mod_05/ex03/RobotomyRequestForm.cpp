/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:40:17 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/23 19:17:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <fstream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "Default_target", 72, 45)
{
	std::cout << UNDER << "RobotomyRequestForm Default Constructor"
		<< RESET << " called with target " << this->getTarget() << "!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << UNDER << "RobotomyRequestForm Parametric Constructor"
		<< RESET << " called with target " << this->getTarget() << "!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	std::cout << UNDER << "RobotomyRequestForm Copy Constructor"
		<< RESET << " called with target " << this->getTarget() << "!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << UNDER << "RobotomyRequestForm Destructor"
		<< RESET << " called with target " << this->getTarget() << "!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	std::cout << "RobotomyRequestForm assignment operator called with target " << this->getTarget() << "!" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::beExecuted(const Bureaucrat &executor) const
{
	std::cout << CYAN << "Bzzz. Bzzz." << RESET << std::endl;
	int random_number = std::rand() % 2;
	if (random_number == 0)
	{
		std::cout << CYAN << "Under the action of " << executor.getName() << ", " << this->getTarget()
			<< " was robotomized successfully!" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << executor.getName() << " executed form but Robotomy on "
			<< this->getTarget() << " failed!" << RESET << std::endl;
	}
}
