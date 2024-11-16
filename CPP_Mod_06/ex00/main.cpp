/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:30:22 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/16 18:30:23 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char* av[])
{
	if (ac != 2)
		std::cout << "Usage: ./convert [literal]" << std::endl;
	else
		ScalarConverter::convert(av[1]);
	return 0;
}
