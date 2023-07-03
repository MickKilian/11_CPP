/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:46:32 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 09:59:47 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class	Fixed {
	public:
		Fixed(void);
		Fixed(int const intNum);
		Fixed(float const fltNum);
		Fixed(Fixed const &fixedNum);
		~Fixed(void);
		Fixed &	operator=(Fixed const &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const newValue);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif // FIXED_H
