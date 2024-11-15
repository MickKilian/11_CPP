/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:55:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/14 21:07:40 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define SIZE 100000

int	main(void)
{
	Span	empty(5);
	std::cout << empty;
	try
	{
		std::cout << GREEN << "Shortest span is : " << empty.shortestSpan() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << GREEN << "Longest span is : " << empty.longestSpan() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	Span	sp = Span(SIZE + 5);
	std::cout << "Adding 5 elements" << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp;
	std::cout << GREEN << "Shortest span is : " << sp.shortestSpan() << RESET << std::endl;
	std::cout << GREEN << "Longest span is : " << sp.longestSpan() << RESET << std::endl;
	std::vector<int>	vec;
	std::cout << "Adding " << SIZE << " elements" << std::endl;
	int		i = 1;
	while (i <= SIZE)
	{
		vec.push_back(i);
		++i;
	}
	sp.addNumber(vec.begin(), vec.end());
	try
	{
		std::cout << GREEN << "Shortest span is : " << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "Longest span is : " << sp.longestSpan() << RESET << std::endl;
		sp.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
