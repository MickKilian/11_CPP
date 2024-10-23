/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:09:18 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/23 18:31:37 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	//************************** TESTS for FORMS **************************
	std::cout << std::endl;
	std::cout << YELLOW << "TEST CONSTRUCTORS for FORMS" << RESET << std::endl;
	try
	{
		std::cout << YELLOW << "Default constructor" << RESET << std::endl;
		Form b10;
		std::cout << b10 << std::endl;
		std::cout << YELLOW << "Parametric constructor" << RESET << std::endl;
		Form b12("B12", 100, 80);
		std::cout << b12 << std::endl;
		std::cout << YELLOW << "Copy constructor" << RESET << std::endl;
		Form *b11 = new Form("B11", 50, 40);
		Form b11_copy = Form(*b11);
		delete b11;
		std::cout << b11_copy << std::endl;
		std::cout << YELLOW << "Assignement operator" << RESET << std::endl;
		Form *b12_heap = new Form("B12_heap", 50, 40);
		Form b12_2_as;
		std::cout << b12_2_as << std::endl;
		b12_2_as = *b12_heap;
		delete b12_heap;
		std::cout << b12_2_as << std::endl;
		std::cout << YELLOW << "Destructors" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "TEST TOO LOW / TOO HIGH GRADES at CREATION for FORMS :" << RESET << std::endl;
	try
	{
		Form b12("B12_high", 151, 80);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << " Next time, please enter a grade between 1 and 150 !" << RESET << std::endl;
	}
	try
	{
		Form b12("B12_low", 10, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << " Next time, please enter a grade between 1 and 150 !" << RESET << std::endl;
	}

	//************************** TESTS SIGN from FORMS **************************
	std::cout << std::endl;
	std::cout << YELLOW << "SIGN from FORM (beSigned)" << RESET << std::endl;
	try
	{
		Bureaucrat smith("Smith", 1);
		Form	b28("B28", 50, 25);
		std::cout << b28 << std::endl;
		try
		{
			b28.beSigned(smith);
			std::cout << b28 << std::endl;
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
	try
	{
		Bureaucrat smith("Smith", 10);
		Form	b46("B46", 5, 2);
		std::cout << b46 << std::endl;
		try
		{
			b46.beSigned(smith);
			std::cout << b46 << std::endl;
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

	//************************** TESTS SIGN from BUREAUCRATS **************************
	std::cout << std::endl;
	std::cout << YELLOW << "SIGN from BUREAUCRAT (signForm)" << RESET << std::endl;
	try
	{
		Bureaucrat smith("Smith", 10);
		Form	b27("B27", 50, 100);
		std::cout << b27 << std::endl;
		try
		{
			smith.signForm(b27);
			std::cout << b27 << std::endl;
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
	try
	{
		Bureaucrat smith("Smith", 10);
		Form	b47("B47", 5, 100);
		std::cout << b47 << std::endl;
		try
		{
			smith.signForm(b47);
			std::cout << b47 << std::endl;
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
