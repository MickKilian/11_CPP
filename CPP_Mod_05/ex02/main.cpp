/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:09:18 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/23 19:19:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	//************************** TESTS for BUREAUCRATS **************************
	std::cout << std::endl;
	std::cout << YELLOW << "TEST CONSTRUCTORS and COPIES for BUREAUCRATS" << RESET << std::endl;
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
	std::cout << GREEN << "TESTS CONSTRUCTORS and COPIES for SHRUBBERY_CREATION_FORMS" << RESET << std::endl;
	std::cout << GREEN << "Default constructor" << RESET << std::endl;
	ShrubberyCreationForm form1;
	std::cout << form1 << std::endl;
	std::cout << GREEN << "Parametric constructor" << RESET << std::endl;
	ShrubberyCreationForm *form1_ptr = new ShrubberyCreationForm("Garden");
	std::cout << *form1_ptr << std::endl;
	std::cout << GREEN << "Copy constructor" << RESET << std::endl;
	ShrubberyCreationForm *form1_cp_ptr = new ShrubberyCreationForm(*form1_ptr);
	delete form1_ptr;
	std::cout << *form1_cp_ptr << std::endl;
	std::cout << GREEN << "Assignement operator" << RESET << std::endl;
	ShrubberyCreationForm form1_eq;
	form1_eq = *form1_cp_ptr;
	delete form1_cp_ptr;
	std::cout << form1_eq << std::endl;
	std::cout << std::endl;
	std::cout << MAGENTA << "TESTS CONSTRUCTORS and COPIES for ROBOTOMY_REQUEST_FORMS" << RESET << std::endl;
	std::cout << MAGENTA << "Default constructor" << RESET << std::endl;
	RobotomyRequestForm form2;
	std::cout << form2 << std::endl;
	std::cout << MAGENTA << "Parametric constructor" << RESET << std::endl;
	RobotomyRequestForm *form2_ptr = new RobotomyRequestForm("PoorGuy");
	std::cout << *form2_ptr << std::endl;
	std::cout << MAGENTA << "Copy constructor" << RESET << std::endl;
	RobotomyRequestForm *form2_cp_ptr = new RobotomyRequestForm(*form2_ptr);
	delete form2_ptr;
	std::cout << *form2_cp_ptr << std::endl;
	std::cout << MAGENTA << "Assignement operator" << RESET << std::endl;
	RobotomyRequestForm form2_eq;
	form2_eq = *form2_cp_ptr;
	delete form2_cp_ptr;
	std::cout << form2_eq << std::endl;
	std::cout << std::endl;
	std::cout << BLUE << "TESTS CONSTRUCTORS and COPIES for PRESIDENTIAL_PARDON_FORMS" << RESET << std::endl;
	std::cout << BLUE << "Default constructor" << RESET << std::endl;
	PresidentialPardonForm form3;
	std::cout << form3 << std::endl;
	std::cout << BLUE << "Parametric constructor" << RESET << std::endl;
	PresidentialPardonForm *form3_ptr = new PresidentialPardonForm("LuckyGuy");
	std::cout << *form3_ptr << std::endl;
	std::cout << BLUE << "Copy constructor" << RESET << std::endl;
	PresidentialPardonForm *form3_cp_ptr = new PresidentialPardonForm(*form3_ptr);
	delete form3_ptr;
	std::cout << *form3_cp_ptr << std::endl;
	std::cout << BLUE << "Assignement operator" << RESET << std::endl;
	PresidentialPardonForm form3_eq;
	form3_eq = *form3_cp_ptr;
	delete form3_cp_ptr;
	std::cout << form3_eq << std::endl;

	//************************** TEST SHRUBBERY_CREATION_FORM **************************
	std::cout << std::endl;
	std::cout << GREEN << "TEST ShrubberyCreationForm" << RESET << std::endl;
	std::cout << GREEN << "Signing permission" << RESET << std::endl;
	ShrubberyCreationForm form1_test = ShrubberyCreationForm("Garden");
	std::cout << form1_test << std::endl;
	Bureaucrat susanna = Bureaucrat("Susanna", 147);
	std::cout << susanna << std::endl;
	try
	{
		susanna.signForm(form1_test);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << "Executing permission from Form" << RESET << std::endl;
	Bureaucrat simon = Bureaucrat("Simon", 1);
	std::cout << simon << std::endl;
	Bureaucrat elton = Bureaucrat("Elton", 50);
	std::cout << elton << std::endl;
	Bureaucrat peter = Bureaucrat("Peter", 140);
	std::cout << peter << std::endl;
	simon.signForm(form1_test);
	try
	{
		form1_test.execute(simon);
		form1_test.execute(elton);
		form1_test.execute(peter);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Form could not be executed because " << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << "Executing permission from Bureaucrat" << RESET << std::endl;
	try
	{
		simon.executeForm(form1_test);
		elton.executeForm(form1_test);
		peter.executeForm(form1_test);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << "Trying to execute unsigned form from Form" << RESET << std::endl;
	ShrubberyCreationForm form1_b = ShrubberyCreationForm("City");
	std::cout << form1_b << std::endl;
	try
	{
		form1_b.execute(simon);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Form could not be executed because " << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << "Trying to execute unsigned form from Bureaucrat" << RESET << std::endl;
	try
	{
		simon.executeForm(form1_b);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << "Trying to execute ShrubberyCreationForm from Bureaucrat with invalid path" << RESET << std::endl;
	ShrubberyCreationForm form1_inv = ShrubberyCreationForm("invalid/path");
	std::cout << form1_inv << std::endl;
	simon.signForm(form1_inv);
	try
	{
		simon.executeForm(form1_inv);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	//************************** TEST_ROBOTOMY_REQUEST_FORM **************************
	std::cout << std::endl;
	std::cout << MAGENTA << "TEST RobotomyRequestForm" << RESET << std::endl;
	std::cout << MAGENTA << "Signing permission" << RESET << std::endl;
	RobotomyRequestForm form2_test = RobotomyRequestForm("PoorGuy");
	std::cout << form2_test << std::endl;
	try
	{
		susanna.signForm(form2_test);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << MAGENTA << "Executing permission from Form" << RESET << std::endl;
	simon.signForm(form2_test);
	try
	{
		form2_test.execute(simon);
		form2_test.execute(elton);
		form2_test.execute(peter);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Form could not be executed because " << e.what() << RESET << std::endl;
	}
	std::cout << MAGENTA << "Executing permission from Bureaucrat" << RESET << std::endl;
	try
	{
		simon.executeForm(form2_test);
		elton.executeForm(form2_test);
		peter.executeForm(form2_test);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << MAGENTA << "Trying to execute unsigned form from Form" << RESET << std::endl;
	RobotomyRequestForm form2_b = RobotomyRequestForm("Ralph");
	std::cout << form2_b << std::endl;
	try
	{
		form2_b.execute(simon);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Form could not be executed because " << e.what() << RESET << std::endl;
	}
	std::cout << MAGENTA << "Trying to execute unsigned form from Bureaucrat" << RESET << std::endl;
	try
	{
		simon.executeForm(form2_b);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	//************************** TEST_PRESIDENTIAL_PARDON_FORM **************************
	std::cout << std::endl;
	std::cout << BLUE << "TEST PresidentialPardonForm" << RESET << std::endl;
	std::cout << BLUE << "Signing permission" << RESET << std::endl;
	PresidentialPardonForm form3_test = PresidentialPardonForm("LuckyGuy");
	std::cout << form3_test << std::endl;
	try
	{
		susanna.signForm(form3_test);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << BLUE << "Executing permission from Form" << RESET << std::endl;
	simon.signForm(form3_test);
	try
	{
		form3_test.execute(simon);
		form3_test.execute(elton);
		form3_test.execute(peter);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Form could not be executed because " << e.what() << RESET << std::endl;
	}
	std::cout << BLUE << "Executing permission from Bureaucrat" << RESET << std::endl;
	try
	{
		simon.executeForm(form3_test);
		elton.executeForm(form3_test);
		peter.executeForm(form3_test);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << BLUE << "Trying to execute unsigned form from Form" << RESET << std::endl;
	PresidentialPardonForm form3_b = PresidentialPardonForm("Betty");
	std::cout << form3_b << std::endl;
	try
	{
		form3_b.execute(simon);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Form could not be executed because " << e.what() << RESET << std::endl;
	}
	std::cout << BLUE << "Trying to execute unsigned form from Bureaucrat" << RESET << std::endl;
	try
	{
		simon.executeForm(form3_b);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "Destructors" << RESET << std::endl;
	return (0);
}
