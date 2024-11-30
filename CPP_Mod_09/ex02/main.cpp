/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:51 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/30 02:02:11 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printTimeProcess(clock_t start, clock_t end, int nb_elem, std::string type, std::string color)
{
	std::cout << "Time to process a range of " << color << nb_elem << RESET << " elements with "
		<< color << type << RESET << " : " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6 << " us" << RESET << std::endl;
}

template < typename T >
bool	checkSorted(T set1, T set2)
{
	if (set1.size() != set2.size())
		return false;
	std::sort(set1.begin(), set1.end());
	for (size_t i = 0; i < set1.size(); ++i)
	{
		if (set1[i] != set2[i])
			return false;
	}
	return true;
}

int	main(int ac, char *av[])
{
	PmergeMe			pmergeme;
	clock_t				start;
	clock_t				end;

	if (ac < 3)
	{
		std::cout << "Usage: ./PmergeMe [list of at least two positive integers]" << std::endl;
		return 0;
	}
	try
	{
		pmergeme.parseData(av, ac - 1);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return 0;
	}
	std::vector<int>	datav_0 = pmergeme.getVector();
	std::deque<int>		datad_0 = pmergeme.getDeque();
	std::cout << CYAN << "Before : " << RESET << datav_0 << std::endl;
	start = clock();
	pmergeme.sortVector();
	end = clock();
	std::cout << CYAN << "After  : " << RESET << pmergeme.getVector() << std::endl;
	if (!checkSorted(datav_0, pmergeme.getVector()))
	{
		std::cout << "Vector was not sorted correctly" << std::endl;
		return 0;
	}
	printTimeProcess(start, end, ac - 1, "std::vector", YELLOW);
	start = clock();
	//pmergeme.sortDeque();
	end = clock();
	if (!checkSorted(datad_0, pmergeme.getDeque()))
	{
		std::cout << "Deque was not sorted correctly" << std::endl;
		return 0;
	}
	printTimeProcess(start, end, ac - 1, "std::deque ", MAGENTA);
	return 0;
}
