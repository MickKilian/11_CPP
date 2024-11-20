/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:42:21 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/19 21:10:48 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <cstdlib>
# include <vector>
# include <algorithm>
# include <ctime>

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define RESET			"\x1b[0m"

class	Span
{
	public:
		Span();
		Span(unsigned int);
		Span(const Span &);
		~Span();

		Span				&operator=(const Span &);
		std::vector<int>	getVec(void) const;
		void				addNumber(int);
		void				addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
		int					shortestSpan(void);
		int					longestSpan(void);

	private:
		std::vector<int>	_vec;
		unsigned int	_maxSize;

	class FullContainerException : public std::exception
	{
		const	char *what() const throw()
		{
			return ("Container is already full!");
		}
	};

	class NoDistanceException : public std::exception
	{
		const	char *what() const throw()
		{
			return ("There are not enough numbers to calculate a distance!");
		}
	};
};

std::ostream &operator<<(std::ostream &o, const Span &span);

#endif
