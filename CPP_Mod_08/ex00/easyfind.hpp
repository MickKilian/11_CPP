/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:42:21 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/20 01:06:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

#define RED				"\x1b[31m"
#define GREEN			"\x1b[32m"
#define YELLOW			"\x1b[33m"
#define RESET			"\x1b[0m"

class ElementNotFoundException : public std::exception
{
	const	char *what() const throw()
	{
		return (" : element could not be found ");
	}
};

template < typename T >
void	easyfind(const T &obj, int elem)
{
	if (std::find(obj.begin(), obj.end(), elem) == obj.end())
		throw ElementNotFoundException();
}

std::ostream &operator<<(std::ostream &o, const std::vector<int> &vec)
{
	unsigned int	i = 0;
	unsigned int	n = vec.size();

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

std::ostream &operator<<(std::ostream &o, const std::list<int> &list)
{
	unsigned int	n = list.size();

	if (n == 0)
	{
		o << RED << "No data" << RESET << std::endl;
		return (o);
	}
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
	{
		o << *it;
		if (it != --list.end())
			o << " | ";
	}
	o << std::endl;
	return (o);
}

std::ostream &operator<<(std::ostream &o, const std::deque<int> &deque)
{
	unsigned int	i = 0;
	unsigned int	n = deque.size();

	if (n == 0)
	{
		o << RED << "No data" << RESET << std::endl;
		return (o);
	}
	while (i < n)
	{
		o << deque[i];
		++i;
		if (i < n)
			o << " | ";
	}
	o << std::endl;
	return (o);
}

#endif
