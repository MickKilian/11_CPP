/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:37:29 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/23 19:23:51 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default_name"), _target("Default_target"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << UNDER << "AForm Default Constructor"
		<< RESET << " called for form " << this->_name << std::endl;
}

AForm::AForm(const std::string &name, const std::string &target, const int gradeToSign, const int gradeToExecute) :
	_name(name), _target(target), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << UNDER << "AForm Parametric Constructor"
			<< RESET << " called for form " << this->_name << std::endl;
	}
}

AForm::AForm(const AForm &other) : _name(other._name), _target(other._target),
		_isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute)
{
	std::cout << UNDER << "AForm Copy Constructor"
		<< RESET << " called for form " << this->_name << std::endl;
}

AForm::~AForm()
{
	std::cout << UNDER << "AForm Destructor"
		<< RESET << " called for form " << this->_name << std::endl;
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	std::cout << UNDER << "AForm Assignment Operator"
		<< RESET << " called for form " << this->_name << std::endl;
	return (*this);
}

const std::string	&AForm::getName(void) const
{
	return (_name);
}

const std::string	&AForm::getTarget(void) const
{
	return (_target);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!_isSigned)
			throw (AForm::UnsignedException());
		if (executor.getGrade() > this->_gradeToExecute)
			throw (AForm::GradeTooLowException());
		this->beExecuted(executor);
	}
	catch (const std::exception &e)
	{
		throw ;
	}
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	o << BOLDWHITE << rhs.getName()
		<< RESET << "(target " << rhs.getTarget()
		<< (rhs.getIsSigned() ? " is signed" : " is NOT signed")
		<< " sign/" << rhs.getGradeToSign()
		<< " execute/" << rhs.getGradeToExecute() << ").";
	std::cout << RESET;
	return (o);
}
