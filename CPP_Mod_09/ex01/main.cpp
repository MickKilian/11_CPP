/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:52:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/25 01:43:41 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char* av[])
{
	RPN rpn;

	if (ac != 2)
		std::cerr << RED << "Usage: ./RPN [\"mathematical expression\"]" << RESET << std::endl;
	else
	{
		try
		{
			rpn.evaluate(av[1]);
		}
		catch (std::exception &e)
		{	
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}

	return 0;
}
