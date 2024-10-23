/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:04:05 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/10 00:40:55 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &);
		PresidentialPardonForm(const PresidentialPardonForm &);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &);

		void	beExecuted(const Bureaucrat &) const;
};

#endif // PRESIDENTIAL_PARDON_FORM_H
