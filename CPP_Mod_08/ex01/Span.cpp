/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:34:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/14 20:57:13 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span &other) : _maxSize(other._maxSize)
{
	int	i = 0;
	std::vector<int>::iterator	it = _vec.begin();
	while (it != _vec.end())
	{
		_vec.push_back(other._vec[i]);
		++i;
		++it;
	}
}

Span::~Span()
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		int	i = 0;
		std::vector<int>::iterator	it = _vec.begin();
		while (it != _vec.end())
		{
			_vec.push_back(other._vec[i]);
			++i;
			++it;
		}
	}
	return (*this);
}

std::vector<int>	Span::getVec(void) const
{
	return (_vec);
}

void	Span::addNumber(int elem)
{
	if (_vec.size() == _maxSize)
		throw FullContainerException();
	_vec.push_back(elem);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it < end; ++it)
	{
		if (_vec.size() == _maxSize)
			throw FullContainerException();
		_vec.push_back(*it);
	}
}

int	Span::shortestSpan(void)
{
	int	shortestSpan;

	if (_vec.size() <= 1)
		throw NoDistanceException();
	std::sort(_vec.begin(), _vec.end());
	shortestSpan = std::abs(_vec[0] - _vec[1]);
	std::vector<int>::iterator	it = _vec.begin();
	while ((it + 1) != _vec.end())
	{
		if (std::abs(*it - *(it + 1)) < shortestSpan)
			shortestSpan = std::abs(*it - *(it + 1));
		++it;
	}
	return (shortestSpan);
}

int	Span::longestSpan(void)
{
	if (_vec.size() <= 1)
		throw NoDistanceException();
	std::sort(_vec.begin(), _vec.end());
	std::vector<int>::iterator	it = _vec.begin();
	while ((it + 1) != _vec.end())
		it++;
	return ((*it) - *(_vec.begin()));
}

std::ostream &operator<<(std::ostream &o, const Span &span)
{
	std::vector<int>	vec = span.getVec();
	unsigned int	n = vec.size();
	unsigned int	i = 0;

	if (n == 0)
	{
		o << RED << "No data" << RESET << std::endl;
		return (o);
	}
	while (i < n)
	{
		o << vec[i];
		++i;
		if (i < n)
			o << " | ";
	}
	o << std::endl;
	return (o);
}
