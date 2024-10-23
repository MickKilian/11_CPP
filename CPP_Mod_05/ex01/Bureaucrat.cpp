/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:37:29 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/21 17:25:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default_name"), _grade(150)
{
	std::cout << UNDER << "Bureaucrat Default Constructor"
		<< RESET << " called for " << _name << "(" << _grade << ")!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		_grade = grade;
		std::cout << UNDER << "Bureaucrat Parametric Constructor"
			<< RESET << " called for " << _name << "(" << _grade << ")!" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << UNDER << "Bureaucrat Copy Constructor"
		<< RESET << " called for " << _name << "(" << _grade << ")!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << UNDER << "Bureaucrat Destructor"
		<< RESET << " called for " << _name << "(" << _grade << ")!" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	std::cout << UNDER << "Bureaucrat Assignment Operator"
		<< RESET << " called for " << _name << "(" << _grade << ")!" << std::endl;
	return (*this);
}

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrGrade(void)
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		_grade--;
		std::cout << CYAN << _name << "'s grade was incremented to " << _grade << RESET << std::endl;
	}
}

void	Bureaucrat::decrGrade(void)
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		_grade++;
		std::cout << CYAN << _name << "'s grade was decremented to " << _grade << RESET << std::endl;
	}
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << RED << this->getName() << " couldn't sign form " << form.getName() << " because " << RESET;
		throw;
	}
	std::cout << CYAN << this->getName() << " signed form " << form.getName() << "." << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << BOLDWHITE << rhs.getName()
		<< RESET << ", bureaucrat grade " << rhs.getGrade() << RESET;
	return (o);
}
