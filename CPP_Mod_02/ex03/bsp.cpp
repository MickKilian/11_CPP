/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:00:21 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 11:46:08 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	vecProduct(Point const a, Point const b, Point const point) {
	return (((a.getX() - point.getX())*(b.getY() - point.getY()) -
			(a.getY() - point.getY())*(b.getX() - point.getX())).toFloat());
}

bool dirVecProduct(Point const a, Point const b, Point const point) {
	return (vecProduct(a, b, point) > 0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	if (!vecProduct(a, b , point) || !vecProduct(b, c, point) || !vecProduct(c, a, point))
		return (0);
	else if ((dirVecProduct(a, b , point) && dirVecProduct(b, c, point) && dirVecProduct(c, a, point)) ||
		(!dirVecProduct(a, b , point) && !dirVecProduct(b, c, point) && !dirVecProduct(c, a, point)))
		return (1);
	else
		return (0);
}
