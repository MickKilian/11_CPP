/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:34:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/22 17:22:20 by mbourgeo         ###   ########.fr       */
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
	if (_vec.size() + std::distance(begin, end) > _maxSize)
		throw FullContainerException();
	_vec.insert(_vec.end(), begin, end);
}

int	Span::shortestSpan(void)
{
	int					shortestSpan;
	std::vector<int>	vec_copy(_vec);

	if (vec_copy.size() <= 1)
		throw NoDistanceException();
	std::sort(vec_copy.begin(), vec_copy.end());
	shortestSpan = std::abs(vec_copy[0] - vec_copy[1]);
	std::vector<int>::iterator	it = vec_copy.begin();
	while ((it + 1) != vec_copy.end())
	{
		if (std::abs(*it - *(it + 1)) < shortestSpan)
			shortestSpan = std::abs(*it - *(it + 1));
		++it;
	}
	return (shortestSpan);
}

int	Span::longestSpan(void)
{
	std::vector<int>	vec_copy(_vec);

	if (_vec.size() <= 1)
		throw NoDistanceException();
	std::sort(vec_copy.begin(), vec_copy.end());
	std::vector<int>::iterator	it = vec_copy.begin();
	while ((it + 1) != vec_copy.end())
		it++;
	return ((*it) - *(vec_copy.begin()));
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
