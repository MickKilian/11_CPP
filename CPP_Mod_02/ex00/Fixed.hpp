/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:46:32 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 01:18:05 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class	Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const &fixedNum);
		~Fixed(void);
		Fixed &	operator=(Fixed const &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const newValue);

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

#endif // FIXED_H
