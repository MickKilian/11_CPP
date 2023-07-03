/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:29:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 09:58:31 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"
#include <iostream>

class Point {
	public:
		Point(void);
		Point(float x, float y);
		Point(Point const &point);
		~Point(void);

		Point &	operator=(Point const &rhs);

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed	_x;
		Fixed	_y;

};

std::ostream	&operator<<(std::ostream &o, Point const &rhs);

#endif //POINT_H
