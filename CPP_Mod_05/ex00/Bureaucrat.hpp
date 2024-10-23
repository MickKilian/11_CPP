/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:25:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/13 23:51:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <stdexcept>
#include <iostream>

#define RED				"\x1b[31m"
#define BOLDRED			"\x1b[31;1m"
#define GREEN			"\x1b[32m"
#define BOLDGREEN		"\x1b[32;1m"
#define YELLOW			"\x1b[33m"
#define BLUE			"\x1b[34m"
#define BOLDBLUE		"\x1b[34;1m"
#define MAGENTA			"\x1b[35m"
#define BOLDMAGENTA		"\x1b[35;1m"
#define CYAN			"\x1b[36m"
#define BOLDCYAN		"\x1b[36;1m"
#define WHITE			"\x1b[37m"
#define BOLDWHITE		"\x1b[37;1m"
#define UNDER			"\x1b[4m"
#define RESET			"\x1b[0m"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &, int);
		Bureaucrat(const Bureaucrat &);
		virtual ~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				incrGrade(void);
		void				decrGrade(void);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too high!");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too low!");
			}
	};

};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &);

#endif // BUREAUCRAT_H
