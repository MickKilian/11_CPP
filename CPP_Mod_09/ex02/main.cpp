/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:51 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/12/09 06:39:08 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char *av[])
{
	if (ac < 3)
	{
		std::cout << RED << "Usage: ./PmergeMe [list of at least two positive integers]" << RESET << std::endl;
		return 0;
	}

	PmergeMe< std::vector<int> >	vec;
	if (vec.sortData(av, ac - 1))
		return 1;
	std::cout << BOLDWHITE << "Before : " << RESET << vec.getDataOriginal() << std::endl;
	std::cout << BOLDWHITE << "After  : " << RESET << vec.getDataSorted() << std::endl;
	std::cout << BOLDWHITE << "Your sort algorithm's number of comparisons = " << vec.getCountComparisons()
		<< " (max : " << vec.getMaxComparisons() << ") "
		<< (vec.getCountComparisons() <= vec.getMaxComparisons() ? GREEN "=> GOOD" : RED "=> NOK")
		<< RESET << std::endl;
	vec.printInfos("std::vector", YELLOW);

	PmergeMe< std::deque<int> >		deq;
	if (deq.sortData(av, ac - 1))
		return 1;
	deq.printInfos("std::deque", MAGENTA);

	PmergeMe< std::list<int> >		lst;
	if (lst.sortData(av, ac - 1))
		return 1;
	lst.printInfos("std::list", CYAN);
	return 0;
}
