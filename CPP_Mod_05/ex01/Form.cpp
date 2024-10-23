/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:37:29 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/23 19:23:33 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default_name"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << UNDER << "Form Default Constructor"
		<< RESET << " called for form " << this->_name << std::endl;
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else
	{
		std::cout << UNDER << "Form Parametric Constructor"
			<< RESET << " called for form " << this->_name << std::endl;
	}
}

Form::Form(const Form &other) : _name(other._name),
		_isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute)
{
	std::cout << UNDER << "Form Copy Constructor"
		<< RESET << " called for form " << this->_name << std::endl;
}

Form::~Form()
{
	std::cout << UNDER << "Form Destructor"
		<< RESET << " called for form " << this->_name << std::endl;
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	std::cout << UNDER << "Form Assignment Operator"
		<< RESET << " called for form " << this->_name << std::endl;
	return (*this);
}

const std::string	&Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << BOLDWHITE << rhs.getName()
		<< RESET << (rhs.getIsSigned() ? " is signed" : " is NOT signed")
		<< " sign/" << rhs.getGradeToSign()
		<< " execute/" << rhs.getGradeToExecute() << ".";
	std::cout << RESET;
	return (o);
}
