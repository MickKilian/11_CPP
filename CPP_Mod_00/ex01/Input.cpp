/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:20:48 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/02/16 23:54:29 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

int	Input::getInput(std::string *input, std::string const text, std::string const color)
{
	if (text != "")
		std::cout << color << text << RESET;
	//std::cin >> input;
	std::getline(std::cin, *input);
	if (not std::cin.eof())
		return 0;
	else
		return 1;
}
