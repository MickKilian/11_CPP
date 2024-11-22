/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:28:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/22 16:08:13 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void ft_print(const T &elem)
{
	std::cout << elem << " ";
}

int main(void)
{
	int	arr_1[] = { 1, 2, 3, 4, 5 };
	std::string	arr_2[] = { "hello", "comment", "ca", "va", "?" };
	std::size_t	size_1 = sizeof(arr_1) / sizeof(arr_1[0]);
	std::size_t	size_2 = sizeof(arr_2) / sizeof(arr_2[0]);

	std::cout << YELLOW << "** TESTS with int" << RESET << std::endl;
	iter(arr_1, size_1, ft_print);
	std::cout << std::endl;
	std::cout << YELLOW << "** TESTS with string" << RESET << std::endl;
	iter(arr_2, size_2, ft_print);
	std::cout << std::endl;
	return (0);
}
