/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:28:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 09:58:12 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
	return;
}

Point::Point(float x, float y) : _x(x), _y(y) {
	return;
}

Point::Point(Point const &point) {
	*this = point;
	return;
}

Point::~Point(void) {
	return;
}

Point &	Point::operator=(Point const &rhs) {
	if (this != &rhs) {
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return (*this);
}

Fixed Point::getX(void) const {
	return (this->_x);
}

Fixed Point::getY(void) const {
	return (this->_y);
}

std::ostream &	operator<<(std::ostream & o, Point const & rhs) {
	o << "(" << rhs.getX() << ", " << rhs.getY() << ")";
	return o;
}
