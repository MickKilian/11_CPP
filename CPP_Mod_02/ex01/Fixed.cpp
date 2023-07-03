/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:46:21 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 09:33:04 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const intNum) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = intNum << this->_fractionalBits;
	return;
}

Fixed::Fixed(float const fltNum) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(fltNum * (1 << this->_fractionalBits));
	return;
}

Fixed::Fixed(Fixed const &fixedNum) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixedNum;
	return;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &	Fixed::operator=(Fixed const &	rhs) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const newValue) {
	//std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = newValue;
}

float	Fixed::toFloat(void) const {
	return ((float)_fixedPointValue / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const {
	return (_fixedPointValue >> _fractionalBits);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
