/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:18:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/22 16:08:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_H
# define TEMPLATES_H

#define YELLOW			"\x1b[33m"
#define RESET			"\x1b[0m"

template < typename T >
void	swap( T &x, T &y )
{
	T	temp;

	temp = x;
	x = y;
	y = temp;
}

template < typename T >
const T	min( const T &x, const T &y )
{
	return ( (x<=y) ? x : y );
}

template < typename T >
const T	max( const T &x, const T &y )
{
	return ( (x>=y) ? x : y );
}

#endif
