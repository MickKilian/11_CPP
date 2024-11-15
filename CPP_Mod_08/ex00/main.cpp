/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:55:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/14 18:36:41 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int	main(void)
{
	std::vector<int>	vec;
	int	elem1 = -10;
	int	elem2 = -18;

	vec.push_back(1);
	vec.push_back(-1);
	vec.push_back(-10);
	vec.push_back(13);
	try
	{
		easyfind(vec, elem1);
		std::cout << GREEN << "Element was found in container." << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		easyfind(vec, elem2);
		std::cout << GREEN << "Element was found in container." << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
