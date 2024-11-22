/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:20:15 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/22 16:05:58 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

#define YELLOW			"\x1b[33m"
#define CYAN			"\x1b[36m"
#define RESET			"\x1b[0m"

template <typename T>
class Array
{
	public:
		Array() : _arr(NULL), _size(0)
		{
		}

		Array(unsigned int n)
		{
			if (n != 0)
			{
				_arr = new T[n]();
				_size = n;
			}
			else
			{
				_arr = NULL;
				_size = 0;
			}
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
