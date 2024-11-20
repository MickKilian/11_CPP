/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:55:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/20 01:08:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vec;
	std::list<int>	list;
	std::deque<int>	deque;
	int	elem1 = -10;
	int	elem2 = -18;

	vec.push_back(1);
	vec.push_back(-1);
	vec.push_back(-10);
	vec.push_back(13);
	list.push_back(-18);
	list.push_back(0);
	list.push_back(5);
	list.push_back(15);
	deque.push_back(2);
	deque.push_back(9);
	deque.push_back(-10);
	deque.push_back(-18);

	std::cout << YELLOW << "TESTS with VECTOR" << RESET << std::endl;
	std::cout << vec;
	try
	{
		easyfind(vec, elem1);
		std::cout << GREEN << elem1 << " : element was found in vec." << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << elem1 << e.what() << "vec." <<RESET << std::endl;
	}
	try
	{
		easyfind(vec, elem2);
		std::cout << GREEN << elem2 << " : element was found in vec." << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << elem2 << e.what() << "vec." <<RESET << std::endl;
	}

	std::cout << YELLOW << "TESTS with LIST" << RESET << std::endl;
	std::cout << list;
	try
	{
		easyfind(list, elem1);
		std::cout << GREEN << elem1 << " : element was found in list." << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << elem1 << e.what() << "list." <<RESET << std::endl;
	}
	try
	{
		easyfind(list, elem2);
		std::cout << GREEN << elem2 << " : element was found in list." << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << elem2 << e.what() << "list." <<RESET << std::endl;
	}

	std::cout << YELLOW << "TESTS with DEQUE" << RESET << std::endl;
	std::cout << deque;
	try
	{
		easyfind(deque, elem1);
		std::cout << GREEN << elem1 << " : element was found in deque." << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << elem1 << e.what() << "deque." <<RESET << std::endl;
	}
	try
	{
		easyfind(deque, elem2);
		std::cout << GREEN << elem2 << " : element was found in deque." << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << elem2 << e.what() << "deque." <<RESET << std::endl;
	}
	return (0);
}
