/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:46:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 11:49:47 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

# define RED			"\x1b[31;1m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define BOLDMAGENTA	"\x1b[35;1m"
# define CYAN			"\x1b[36m"
# define RESET			"\x1b[0m"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	printInfo(Point const a, Point const b, Point const c, Point const m) {
	std::cout << "Point a" << a << std::endl;
	std::cout << "Point b" << b << std::endl;
	std::cout << "Point c" << c << std::endl;
	std::cout << "Point m" << m << std::endl;
	return;
}

void	printInfo(Point const m) {
	std::cout << "Point m" << m << std::endl;
	return;
}

void	answerIsInside(Point const a, Point const b, Point const c, Point const point) {
	bsp(a, b, c, point) ? std::cout << GREEN << "m is inside triangle abc" : std::cout << RED << "m is not inside triangle abc";
	std::cout << RESET << std::endl;
	return;
}

int	main(void) {
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);
	Point m;

	m = a;
	printInfo(a, b, c, m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = b;
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = c;
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(5, 1);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(5, 0);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(5, 5);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(5, 4.9);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(5, 5.1);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(1, 5);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(2.1, 2.5);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(10.6, 10.2);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(-0.5, 1);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(-0.5, -1);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	m = Point(0.01, 0.01);
	printInfo(m);
	answerIsInside(a, b, c, m);
	std::cout << std::endl;

	return 0;
}
