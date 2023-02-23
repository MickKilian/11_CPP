/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:20:48 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/02/23 00:49:06 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"



int	Input::getInput(std::string& input, const std::string& text, const std::string& color)
{
	input.clear();
	while (not std::cin.eof() and (input.empty() or checkInput(input)))
	{
		if (text != "")
			std::cout << color << text << RESET;
		std::getline(std::cin, input);
		input = split(input);
	}
	if (not std::cin.eof())
		return 0;
	else
	{
		std::cout << std::endl;
		return 1;
	}
}

int	Input::checkInput(const std::string& input)
{
	int	i;

	i = 0;
	while (input[i] and not std::iscntrl(input[i]) and input[i] != 127)
		i++;
	if (not input[i])
		return 0;
	else
		return 1;
}

std::string 	Input::split(const std::string& str)
{
	std::stringstream ss(str);
	std::string       ret;
	std::string       word;

	while (ss >> word) {
		ret.append(word + ' ');
	}
	if (word.empty())
		return word;
	ret.erase(ret.size() - 1);
	return ret;
}
