/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:30:07 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/30 03:29:33 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_H
# define PMERGE_ME_H

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <utility>
# include <vector>
# include <deque>
# include <list>
# include <algorithm>
# include <iterator>
# include <cmath>

#define RESET			"\x1b[0m"
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

class PmergeMe
{

	private:
		std::vector<int>	_datav;
		std::deque<int>		_datad;
		std::list<int>		_datal;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &);


		std::vector<int>	getVector(void) const;
		std::deque<int>		getDeque(void) const;
		std::list<int>		getList(void) const;
		void				parseData(char **&, size_t);
		void				sortVector(void);
		void				sortDeque(void);
		void				sortList(void);

	class TooLargeNumberException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: too large a number.");
			}
	};

	class NotAPositiveNumberException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: not a positive number.");
			}
	};
};

extern int stepCount;

/*template <typename Iterator>
void mergeOld(Iterator begin_highs, Iterator end_highs, Iterator begin_lows, Iterator end_lows)
{
	Iterator	mid_highs = begin_highs;
	std::advance(mid_highs, std::distance(begin_highs, end_highs) / 2);
	Iterator	mid_lows = begin_lows;
	std::advance(mid_lows, std::distance(begin_lows, end_lows) / 2);

	std::vector<int>	temp_highs;
	std::vector<int>	temp_lows;

	Iterator	left_highs = begin_highs;
	Iterator	right_highs = mid_highs;
	Iterator	left_lows = begin_lows;
	Iterator	right_lows = mid_lows;

	while (left_highs != mid_highs && right_highs != end_highs)
	{
		std::cout << MAGENTA << "Comparing " << *left_highs << " and " << *right_highs << RESET << std::endl;
		stepCount++;
		if (*left_highs <= *right_highs)
		{
			temp_highs.push_back(*left_highs);
			++left_highs;
			temp_lows.push_back(*left_lows);
			++left_lows;
		}
		else
		{
			temp_highs.push_back(*right_highs);
			++right_highs;
			temp_lows.push_back(*right_lows);
			++right_lows;
		}
	}
	while (left_highs != mid_highs)
	{
		temp_highs.push_back(*left_highs);
		++left_highs;
		temp_lows.push_back(*left_lows);
		++left_lows;
	}
	while (right_highs != end_highs)
	{
		temp_highs.push_back(*right_highs);
		++right_highs;
		temp_lows.push_back(*right_lows);
		++right_lows;
	}

	Iterator	it_highs = begin_highs;
	for (std::vector<int>::iterator it_temp_highs = temp_highs.begin(); it_temp_highs != temp_highs.end(); ++it_temp_highs)
	{
		*it_highs = *it_temp_highs;
		++it_highs;
	}
	Iterator	it_lows = begin_lows;
	for (std::vector<int>::iterator it_temp_lows = temp_lows.begin(); it_temp_lows != temp_lows.end(); ++it_temp_lows)
	{
		*it_lows = *it_temp_lows;
		++it_lows;
	}
}*/

template <typename Iterator>
void merge(Iterator begin_highs, Iterator end_highs)
{
	std::cout << MAGENTA << "Working with " << *begin_highs << " and " << *end_highs << RESET << std::endl;
	Iterator	mid_highs = begin_highs;
	std::advance(mid_highs, std::distance(begin_highs, end_highs) / 2);

	std::vector<int>	temp_highs;

	Iterator	left_highs = begin_highs;
	Iterator	right_highs = mid_highs;

	while (left_highs != mid_highs && right_highs != end_highs)
	{
		std::cout << MAGENTA << "Comparing " << *left_highs << " and " << *right_highs << RESET << std::endl;
		stepCount++;
		if (*left_highs <= *right_highs)
		{
			temp_highs.push_back(*left_highs);
			++left_highs;
		}
		else
		{
			temp_highs.push_back(*right_highs);
			++right_highs;
		}
	}
	while (left_highs != mid_highs)
	{
		temp_highs.push_back(*left_highs);
		++left_highs;
	}
	while (right_highs != end_highs)
	{
		temp_highs.push_back(*right_highs);
		++right_highs;
	}

	Iterator	it_highs = begin_highs;
	for (std::vector<int>::iterator it_temp_highs = temp_highs.begin(); it_temp_highs != temp_highs.end(); ++it_temp_highs)
	{
		*it_highs = *it_temp_highs;
		++it_highs;
	}
}

/*template <typename Iterator>
void	mergeInsertOld(Iterator begin_highs, Iterator end_highs, Iterator begin_lows, Iterator end_lows)
{
	if (std::distance(begin_highs, end_highs) <= 1)
		return;

	Iterator	mid_highs = begin_highs;
	std::advance(mid_highs, std::distance(begin_highs, end_highs) / 2);
	Iterator	mid_lows = begin_lows;
	std::advance(mid_lows, std::distance(begin_lows, end_lows) / 2);

	mergeInsertOld(begin_highs, mid_highs, begin_lows, mid_lows);
	mergeInsertOld(mid_highs, end_highs, mid_lows, end_lows);

	merge(begin_highs, end_highs, begin_lows, end_lows);
}*/

template <typename Iterator>
void	mergeInsert(Iterator begin_highs, Iterator end_highs)
{
	if (std::distance(begin_highs, end_highs) <= 1)
		return;

	Iterator	mid_highs = begin_highs;
	std::advance(mid_highs, std::distance(begin_highs, end_highs) / 2);

	mergeInsert(begin_highs, mid_highs);
	mergeInsert(mid_highs, end_highs);

	merge(begin_highs, end_highs);
}

template <typename Iterator>
std::vector<int>::iterator	binarySearch(Iterator begin, Iterator end, const int &value)
{
	while (begin != end)
	{
		std::vector<int>::iterator mid = begin + (end - begin) / 2;
		stepCount++;
		std::cout << MAGENTA << "Comparing " << *mid << " and " << value << RESET << std::endl;
		if (*mid < value)
			begin = mid + 1;
		else
			end = mid;
	}
	return begin;
}


std::ostream &operator<<(std::ostream &o, const std::vector<int> &);
std::ostream &operator<<(std::ostream &o, const std::deque<int> &);

#endif
