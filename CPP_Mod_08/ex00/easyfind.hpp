/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:42:21 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/14 18:05:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <algorithm>

#define RED				"\x1b[31m"
#define GREEN			"\x1b[32m"
#define RESET			"\x1b[0m"

class ElementNotFoundException : public std::exception
{
	const	char *what() const throw()
	{
		return ("Element could not be found.");
	}
};

template < typename T >
void	easyfind(const T &obj, int elem)
{
	if (std::find(obj.begin(), obj.end(), elem) == obj.end())
		throw ElementNotFoundException();
}

#endif
