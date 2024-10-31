/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:20:15 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/31 23:55:45 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

#define RED				"\x1b[31m"
#define BOLDRED			"\x1b[31;1m"
#define GREEN			"\x1b[32m"
#define BOLDGREEN		"\x1b[32;1m"
#define YELLOW			"\x1b[33m"
#define BLUE			"\x1b[34m"
#define BOLDBLUE		"\x1b[34;1m"
#define MAGENTA			"\x1b[35m"
#define BOLDMAGENTA		"\x1b[35;1m"
#define CYAN			"\x1b[36m"
#define BOLDCYAN		"\x1b[36;1m"
#define WHITE			"\x1b[37m"
#define BOLDWHITE		"\x1b[37;1m"
#define UNDER			"\x1b[4m"
#define RESET			"\x1b[0m"

template <typename T>
class Array
{
	public:
		Array() : _arr(NULL), _size(0)
		{
		}

		Array(int n) : _arr(new T[n]()), _size(n)
		{
		}

		~Array()
		{
			delete[] _arr;
		}

		Array(const Array &other) : _arr(new T[other.size()]()), _size(other.size())
		{
			for (std::size_t i = 0; i < other.size(); ++i)
				(*this)[i] = other._arr[i];
		}

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] _arr;
				_size = other.size();
				_arr = new T[_size];
				for (std::size_t i = 0; i < other.size(); ++i)
					(*this)[i] = other._arr[i];
			}
			return (*this);
		}

		T	&operator[](std::size_t i) const
		{
			if (i < 0 || i >= size())
				throw OutOfRangeException();
			return (_arr[i]);
		}

		std::size_t	size(void) const
		{
			return (_size);
		}

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Index is out of range!");
				}
		};

	private:
		T		*_arr;
		size_t	_size;
};

#endif
