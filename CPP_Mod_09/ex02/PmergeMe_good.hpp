/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_good.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:30:07 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/12/19 09:05:29 by mbourgeo         ###   ########.fr       */
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
# include <ctime>

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

template < typename T >
class PmergeMe
{

	private:
		T		_dataOriginal;
		T		_dataProcessed;
		int		_nbElem;
		clock_t	_parsingTime;
		clock_t	_sortingTime;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &);


		T		getDataOriginal(void) const;
		T		getDataSorted(void) const;
		int		getNbElem(void) const;
		clock_t	getParsingTime(void) const;
		clock_t	getSortingTime(void) const;
		void	parseData(char **&, size_t);
		bool	sortData(char **&, size_t);
		bool	checkSorted(void);
		clock_t	computeTime(clock_t, clock_t);
		void	printInfos(const std::string &, const std::string &);

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

std::ostream &operator<<(std::ostream &o, const std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		o << vec[i] << " ";
	return (o);
}

std::ostream &operator<<(std::ostream &o, const std::deque<int> &deq)
{
	for (size_t i = 0; i < deq.size(); ++i)
		o << deq[i] << " ";
	return (o);
}

std::ostream &operator<<(std::ostream &o, const std::list<int> &lst)
{
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
		o << *it << " ";
	return (o);
}

template < typename T >
PmergeMe<T>::PmergeMe()
{
}

template < typename T >
PmergeMe<T>::PmergeMe (const PmergeMe &other) : _dataOriginal(other._dataOriginal),
	_dataProcessed(other._dataProcessed), _nbElem(other._nbElem),
	_parsingTime(other._parsingTime), _sortingTime(other._sortingTime)
{
}

template < typename T >
PmergeMe<T>::~PmergeMe()
{
}

template < typename T >
PmergeMe<T>	&PmergeMe<T>::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_dataOriginal = other._dataOriginal;
		this->_dataProcessed = other._dataProcessed;
		this->_nbElem = other._nbElem;
		this->_parsingTime = other._parsingTime;
		this->_sortingTime = other._sortingTime;
	}
	return (*this);
}

template < typename T >
T	PmergeMe<T>::getDataOriginal(void) const
{
	return (_dataOriginal);
}

template < typename T >
T	PmergeMe<T>::getDataSorted(void) const
{
	return (_dataProcessed);
}

template < typename T >
int	PmergeMe<T>::getNbElem(void) const
{
	return (_nbElem);
}

template < typename T >
clock_t	PmergeMe<T>::getParsingTime(void) const
{
	return (_parsingTime);
}

template < typename T >
clock_t	PmergeMe<T>::getSortingTime(void) const
{
	return (_sortingTime);
}

template < typename T >
void	PmergeMe<T>::parseData(char** &input, size_t sequence_size)
{
	long	number;
	char	*end_ptr;

	for (size_t i = 0; i < sequence_size; ++i)
	{
		number = strtod(std::string(input[i + 1]).c_str(), &end_ptr);
		if (*end_ptr != '\0' || number < 0)
			throw PmergeMe::NotAPositiveNumberException();
		if (number > std::numeric_limits<int>::max())
			throw PmergeMe::TooLargeNumberException();
		_dataOriginal.push_back(number);
	}
}

template < typename T >
clock_t	PmergeMe<T>::computeTime(clock_t start, clock_t end)
{
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6);
}

void	printTimeProcessing(clock_t parsing, clock_t sorting, int nb_elem, std::string type, std::string color)
{
	std::cout << "Time to process a range of " << color << nb_elem << RESET << " elements with "
		<< color << type << RESET << " -> "
		<< "parsing : " << color << parsing << RESET << " us"
		<< ", sorting : " << color << sorting << RESET << " us" << std::endl;
}

template < typename T >
void	PmergeMe<T>::printInfos(const std::string &type, const std::string &color)
{
	std::cout << color << "\n+-";
	for (size_t i = 0; i < type.size(); ++i)
		std::cout << "-";
	std::cout << "-+" << RESET;
	std::cout << color << "\n| " << type << " |" << RESET;
	std::cout << color << "\n+-";
	for (size_t i = 0; i < type.size(); ++i)
		std::cout << "-";
	std::cout << "-+" << RESET << std::endl;
	printTimeProcessing(getParsingTime(), getSortingTime(), getNbElem(), type, color);
	std::cout << color << "After  : " << RESET << getDataSorted() << (checkSorted() ? GREEN "=> SORTED" : RED "=> NOT SORTED") << RESET << std::endl;
}

template < typename T >
bool	PmergeMe<T>::checkSorted()
{
	typename T::const_iterator it = _dataProcessed.begin();
	typename T::const_iterator next = it;

	if (_dataProcessed.size() < 2 || _dataProcessed.size() != _dataOriginal.size())
		return 1;
	next++;

	while (next != _dataProcessed.end())
	{
		if (*it > *(next))
			return 0;
		++it;
		++next;
	}
	return 1;
}

template < typename T >
inline void	printSeq(T sequence)
{
	for (typename T::iterator it = sequence.begin(); it != sequence.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
}

template < typename T >
inline void	printSeqLvl(T sequence, int level)
{
	int	count = 0;
	int	total = 0;
	int	nb_elem = pow(2, level - 1);

	for (typename T::iterator it = sequence.begin(); it != sequence.end(); ++it)
	{
		++count;
		++total;
		if ((double)total / (2 * nb_elem) > sequence.size() / (2 * nb_elem))
		{
			if ((double)total / nb_elem > sequence.size() / nb_elem)
				std::cout << RED << *it << RESET << (total % 2 ? "-" : " ");
			else
				std::cout << GREEN << *it << (total % 2 ? "-" : " ");
		}
		else if ((count - 1) / nb_elem >= 1)
			std::cout << WHITE << *it << (total % 2 ? "-" : " ");
		else
			std::cout << BLUE << *it << (total % 2 ? "-" : " ");
		if (count >= 2 * nb_elem)
			count = 0;
	}
	std::cout << RESET << std::endl;
}

std::vector<int>	generateJacobsthalSequence(int n)
{
	std::vector<int>	sequence;
	int					power = 2;
	int					a = 1;
	while (1)
	{
		sequence.push_back(a);
		a = pow(2, power) - a;
		power += 1;
		if (a > n)
		{
			sequence.push_back(a);
			break;
		}
	}
	return sequence;
}

template < typename T >
inline T	getAdvance(T current, int shift)
{
		std::advance(current, shift);
		return (current);
}

template < typename T >
inline int	getElement(T begin, int nb_elem)
{
		std::advance(begin, nb_elem - 1);
		return (*begin);
}

template < typename T >
inline T	getPrevious(T current, int nb_elem)
{
		std::advance(current, -nb_elem);
		return (current);
}

template < typename T >
inline T	getNext(T current, int nb_elem)
{
		std::advance(current, nb_elem);
		return (current);
}

template < typename T >
inline T	binarySearch(T begin, T end, int elem_search, int nb_elem)
{
	T	pos = begin;
	if (std::distance(begin, end) == 0)
		return (pos);
	T	mid = getAdvance(begin, (std::distance(begin, end) / nb_elem / 2) * nb_elem);
	if (elem_search < getElement(mid, nb_elem))
		pos = binarySearch(begin, mid, elem_search, nb_elem);
	else
		pos = binarySearch(getNext(mid, nb_elem), end, elem_search, nb_elem);
	return (pos);
}

template < typename T >
inline void	insertRange(T &sequence, typename T::iterator pos, typename T::iterator start, typename T::iterator end)
{
	sequence.insert(pos, start, end);
}

template < typename T >
inline T	fordJohnsonInsertion(T sequence, int level)
{
	size_t	count = 0;
	int		nb_elem = pow(2, level - 1);
	size_t	nb_as = sequence.size() / (2 * nb_elem);
	size_t	nb_bs = sequence.size() / (2 * nb_elem) + (sequence.size() - (sequence.size() / (2 * nb_elem) * (2 * nb_elem))) / nb_elem;

	//generate main_seq
	//add b1 to main_seq
	T	main_seq;
	insertRange(main_seq, main_seq.begin(), sequence.begin(), getNext(sequence.begin(), nb_elem));
	//add as to main_seq
	for (size_t i = 0; i < nb_as; ++i)
		insertRange(main_seq, main_seq.end(), getAdvance(sequence.begin(), (2 * i + 1) * nb_elem), getAdvance(sequence.begin(), (2 * (i + 1)) * nb_elem));

	//insert bs using jacobsthal
	std::vector<int>	jacobsthalIndices = generateJacobsthalSequence(nb_as);
	int	shift = 0;
	if (nb_as > 1)
	{
		size_t temp = 1;
		for (size_t j = 1; j < jacobsthalIndices.size(); ++j)
		{
			shift = 0;
			for (size_t i = jacobsthalIndices[j]; i > temp; --i)
			{
				if (i > nb_as)
					continue;
				typename T::iterator	pos = binarySearch(main_seq.begin(), getAdvance(main_seq.begin(), (i + count - shift) * nb_elem), getElement(getAdvance(sequence.begin(), (2 * (i - 1)) * nb_elem), nb_elem), nb_elem);
				if (pos == getAdvance(main_seq.begin(), (i + count - shift) * nb_elem))
					shift++;
				insertRange(main_seq, pos, getAdvance(sequence.begin(), (2 * i - 2) * nb_elem), getAdvance(sequence.begin(), (2 * i - 1) * nb_elem));
				++count;
			}
			temp = jacobsthalIndices[j];
		}
	}

	//insert last b if there is one
	if (nb_as != nb_bs)
	{
		int i = nb_bs;
		typename T::iterator	pos = binarySearch(main_seq.begin(), main_seq.end(), getElement(getAdvance(sequence.begin(), (2 * (i - 1)) * nb_elem), nb_elem), nb_elem);
		insertRange(main_seq, pos, getAdvance(sequence.begin(), (2 * i - 2) * nb_elem), getAdvance(sequence.begin(), (2 * i - 1) * nb_elem));
	}

	//add odd elements
	for (typename T::iterator it = getAdvance(sequence.begin(), nb_as * 2 * nb_elem + (nb_bs - nb_as) * nb_elem);
			it != sequence.end(); ++it)
		main_seq.push_back(*it);
	return (main_seq);
}

template < typename T >
inline T	fordJohnsonSort(T sequence, int level)
{
	size_t	count = 0;
	int		nb_elem = pow(2, level - 1);

	for (typename T::iterator it = sequence.begin(); it != sequence.end(); )
	{
		count += 2 * nb_elem;
		if (count > sequence.size())
			break;
		if (*getAdvance(it, nb_elem - 1) > *getAdvance(it, (2 * nb_elem) - 1))
			for (int i = 0; i < nb_elem; ++i)
				std::swap(*getAdvance(it, i), *getAdvance(it, nb_elem + i));
		std::advance(it, 2 * nb_elem);
	}
	if (2 * pow(2, level) <= sequence.size())
		sequence = fordJohnsonSort(sequence, level + 1);
	sequence = fordJohnsonInsertion(sequence, level);
	return (sequence);
}

template < typename T >
bool	PmergeMe<T>::sortData(char** &input, size_t sequence_size)
{
	clock_t	start_parsing;
	clock_t	end_parsing;
	clock_t	start_sorting;
	clock_t	end_sorting;

	start_parsing = clock();
	try
	{
		parseData(input, sequence_size);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}
	end_parsing = clock();
	_nbElem = sequence_size;
	start_sorting = clock();
	_dataProcessed = fordJohnsonSort(_dataOriginal, 1);
	end_sorting = clock();
	if (!checkSorted())
		return 1;
	_parsingTime = computeTime(start_parsing, end_parsing);
	_sortingTime = computeTime(start_sorting, end_sorting);
	return 0;
}

#endif
