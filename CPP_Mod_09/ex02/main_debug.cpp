/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:51 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/12/09 06:39:20 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe_debug.hpp"

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

	vec.printInfos("std::vector", YELLOW);

	return 0;
}
