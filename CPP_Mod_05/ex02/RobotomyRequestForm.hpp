/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:04:05 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/10 00:40:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &);
		RobotomyRequestForm(const RobotomyRequestForm &);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &);

		void	beExecuted(const Bureaucrat &) const;
};

#endif // ROBOTOMY_REQUEST_FORM_H
