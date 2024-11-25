/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:57:08 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/25 01:53:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isDigit(int c)
{
	return (c >= '0' && c <='9');
}

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other) : _data(other._data)
{
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->_data = other._data;
	return (*this);
}

void	RPN::compute(int operation)
{
	int	a, b;

	if (_data.empty())
		throw RPN::InvalidExpressionException();
	b = _data.top();
	_data.pop();
	if (_data.empty())
		throw RPN::InvalidExpressionException();
	a = _data.top();
	_data.pop();
	switch (operation)
	{
		case '+':
			_data.push(a + b);
			break;
		case '-':
			_data.push(a - b);
			break;
		case '*':
			_data.push(a * b);
			break;
		case '/':
			_data.push(a / b);
			break;
	}
}

void	RPN::evaluate(const std::string &expression)
{
	RPN	rpn;
	int	i = 0;

	while (expression[i] == 32)
		i++;
	while(true)
	{
		if (isdigit(expression[i]))
			_data.push(expression[i++] - 48);
		else if (std::string("+-*/").find(expression[i]) != std::string::npos)
			compute(expression[i++]);
		else
			throw RPN::InvalidExpressionException();
		if (!expression[i])
			break;
		else if (expression[i] != 32)
			throw RPN::InvalidExpressionException();
		while (expression[i] == 32)
			i++;
		if (!expression[i])
			break;
	}
	if (_data.size() != 1)
		throw RPN::InvalidExpressionException();
	std::cout << _data.top() << std::endl;
}
