/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:18:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/31 20:18:51 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_H
# define TEMPLATES_H

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
