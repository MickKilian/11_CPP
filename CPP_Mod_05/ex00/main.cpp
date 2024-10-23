/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:09:18 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/23 18:20:16 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	//************************** TESTS for BUREAUCRATS **************************
	std::cout << std::endl;
	std::cout << YELLOW << "TEST CONSTRUCTORS and COPIES for BUREAUCRATS" << RESET << std::endl;
	try
	{
		std::cout << YELLOW << "Default constructor" << RESET << std::endl;
		Bureaucrat smith1;
		std::cout << smith1 << std::endl;
		std::cout << YELLOW << "Parametric constructor" << RESET << std::endl;
		Bureaucrat *smith2 = new Bureaucrat("Smith", 10);
		std::cout << *smith2 << std::endl;
		std::cout << YELLOW << "Copy constructor" << RESET << std::endl;
		Bureaucrat *smith_cp = new Bureaucrat(*smith2);
		delete smith2;
		std::cout << *smith_cp << std::endl;
		std::cout << YELLOW << "Assignement operator" << RESET << std::endl;
		Bureaucrat smith_eq;
		smith_eq = *smith_cp;
		delete smith_cp;
		std::cout << smith_eq << std::endl;
		std::cout << YELLOW << "Destructors" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	//************************** TESTS EXCEPTIONS for BUREAUCRATS **************************
	std::cout << std::endl;
	std::cout << YELLOW << "TESTS TOO LOW / TOO HIGH GRADES at CREATION for BUREAUCRATS :" << RESET << std::endl;
	try
	{
		Bureaucrat smith("Smith", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << " Next time, please enter a grade between 1 and 150 !" << RESET << std::endl;
	}
	try
	{
		Bureaucrat elton("Elton", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << " Next time, please enter a grade between 1 and 150 !" << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "TESTS UPGRADE / DOWNGRADE for BUREAUCRATS" << RESET << std::endl;
	try
	{
		Bureaucrat smith("Smith", 10);
		std::cout << smith << std::endl;
		Bureaucrat elton("Elton", 145);
		std::cout << elton << std::endl;
		try
		{
			smith.incrGrade();
			smith.incrGrade();
			smith.incrGrade();
			smith.incrGrade();
			smith.incrGrade();
			smith.incrGrade();
			smith.incrGrade();
			smith.incrGrade();
			smith.incrGrade();
			smith.incrGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		try
		{
			elton.decrGrade();
			elton.decrGrade();
			elton.decrGrade();
			elton.decrGrade();
			elton.decrGrade();
			elton.decrGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
