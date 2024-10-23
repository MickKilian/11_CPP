/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:25:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/10 00:41:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_H
#define A_FORM_H

#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const std::string	_target;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		virtual	void		beExecuted(const Bureaucrat &) const = 0;

	public:
		AForm();
		AForm(const std::string &, const std::string &, const int, const int);
		AForm(const AForm &);
		virtual ~AForm() = 0;
		AForm &operator=(const AForm &);

		const std::string	&getName(void) const;
		const std::string	&getTarget(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat &);
		void				execute(Bureaucrat const &) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("grade is too high!");
				}
		};
	
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("grade is too low!");
				}
		};
	
		class UnsignedException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("form is not signed yet!");
				}
		};

};

std::ostream	&operator<<(std::ostream &o, AForm const &);

#endif // A_FORM_H
