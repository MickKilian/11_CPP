/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:37:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/30 00:49:28 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe (const PmergeMe &other) : _datav(other._datav), _datad(other._datad), _datal(other._datal)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_datav = other._datav;
		this->_datad = other._datad;
		this->_datal = other._datal;
	}
	return (*this);
}

std::vector<int>	PmergeMe::getVector(void) const
{
	return (_datav);
}

std::deque<int>	PmergeMe::getDeque(void) const
{
	return (_datad);
}

std::list<int>	PmergeMe::getList(void) const
{
	return (_datal);
}

void	PmergeMe::parseData(char** &input, size_t set_size)
{
	long				number;
	char				*end_ptr;

	for (size_t i = 0; i < set_size; ++i)
	{
		number = strtod(std::string(input[i + 1]).c_str(), &end_ptr);
		if (*end_ptr != '\0' || number < 0)
			throw PmergeMe::NotAPositiveNumberException();
		if (number > std::numeric_limits<int>::max())
			throw PmergeMe::TooLargeNumberException();
		_datav.push_back(number);
		_datad.push_back(number);
		_datal.push_back(number);
	}
}

bool	compareByFirst(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.first < b.first);
}

/*int	pickListElement(const std::list<int> &ref, size_t index)

	std::list<int> copy = ref;
	std::list<int>::iterator it = copy.begin();

	std::advance(it, index);
	return(*it);
}*/

/*std::list<int>::iterator	binarySearch(std::list<int>::iterator begin, std::list<int>::iterator end, const int &value, int &stepCount)
{
	while (begin != end)
	{
		stepCount++;
		int	std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);

		Iterator mid = begin;
		std::advance(mid, distance / 2);
		if (*mid < value)
		{
			begin = mid;
			++begin;
		}
		else
			end = mid;
	}
	return begin;
}*/

int stepCount;

std::vector<int>::iterator	binaryPairFirstSearch(std::vector<int>::iterator begin, std::vector<int>::iterator end, const int &value)
{
	while (begin != end)
	{
		stepCount++;
		std::vector<int>::iterator mid = begin + (end - begin) / 2;
		if (*mid < value)
			begin = mid + 2;
		else
			end = mid;
	}
	return begin;
}

void	PmergeMe::sortVector(void)
{
	size_t								half = (_datav.size() / 2);
	bool								odd_size = _datav.size() % 2;
	std::vector< std::pair<int, int> >	data_pairs;
	std::vector<int>					left;
	std::vector<int>					right;

	stepCount = 0;
	for (std::vector<int>::iterator it = _datav.begin(); it != _datav.end(); it += 2)
	{
		if (it + 1 == _datav.end())
			break;
		if (*it < *(it + 1))
			std::swap(*it, *(it + 1));
	}
	
    std::sort(data_pairs.begin(), data_pairs.end(), compareByFirst);
	for (std::vector< std::pair<int, int> >::iterator it = data_pairs.begin(); it != data_pairs.end(); ++it)
	{
		left.push_back(it->first);
		right.push_back(it->second);
	}
	left.insert(left.begin(), *(right.begin()));
	size_t	jacobsthal = 0;
	size_t	count = 1;
	for (int power = 1; count < half; ++power)
	{
		jacobsthal = (1 << power) - jacobsthal;
		if (count + jacobsthal > half)
			jacobsthal = half - count;
		for (size_t i = jacobsthal; i > 0; --i)
			left.insert(std::lower_bound(left.begin(), left.begin() + 2 * (count + jacobsthal) - 1 - i,
						*(right.begin() + count + i - 1)), *(right.begin() + count + i - 1));
		count += jacobsthal;
	}
	if (odd_size)
		left.insert(std::lower_bound(left.begin(), left.end(), _datav.back()), _datav.back());
	_datav = left;
}

void	PmergeMe::sortDeque(void)
{
	size_t								half = (_datad.size() / 2);
	bool								odd_size = _datad.size() % 2;
	std::deque< std::pair<int, int> >	data_pairs;
	std::deque<int>					left;
	std::deque<int>					right;
	for (std::deque<int>::iterator it = _datad.begin(); it != _datad.end(); it += 2)
	{
		if (it + 1 == _datad.end())
			break;
		if (*it > *(it + 1))
			data_pairs.push_back(std::make_pair(*it, *(it + 1)));
		else
			data_pairs.push_back(std::make_pair(*(it + 1), *it));
	}
	std::sort(data_pairs.begin(), data_pairs.end(), compareByFirst);
	for (std::deque< std::pair<int, int> >::iterator it = data_pairs.begin(); it != data_pairs.end(); ++it)
	{
		left.push_back(it->first);
		right.push_back(it->second);
	}
	left.push_front(*right.begin());
	size_t	jacobsthal = 0;
	size_t	count = 1;
	for (int power = 1; count < half; ++power)
	{
		jacobsthal = (1 << power) - jacobsthal;
		if (count + jacobsthal > half)
			jacobsthal = half - count;
		for (size_t i = jacobsthal; i > 0; --i)
			left.insert(std::lower_bound(left.begin(), left.begin() + 2 * (count + jacobsthal) - 1 - i,
						*(right.begin() + count + i - 1)), *(right.begin() + count + i - 1));
		count += jacobsthal;
	}
	if (odd_size)
		left.insert(std::lower_bound(left.begin(), left.end(), _datad.back()), _datad.back());
	_datad = left;
}

/*void	PmergeMe::sortList(void)
{
	size_t								half = (_datal.size() / 2);
	bool								odd_size = _datal.size() % 2;
	std::list< std::pair<int, int> >	data_pairs;
	std::list<int>						left;
	std::list<int>						right;
	for (size_t i = 0; i < half; ++i)
	{
		if (pickListElement(_datal, 2 * i) > pickListElement(_datal, (2 * i) + 1))
			data_pairs.push_back(std::make_pair(pickListElement(_datal, 2 * i), pickListElement(_datal, (2 * i) + 1)));
		else
			data_pairs.push_back(std::make_pair(pickListElement(_datal, (2 * i) + 1), pickListElement(_datal, 2 * i)));
	}
	std::sort(data_pairs.begin(), data_pairs.end(), compareByFirst);
	for (std::list< std::pair<int, int> >::iterator it = data_pairs.begin(); it != data_pairs.end(); ++it)
	{
		left.push_back(it->first);
		right.push_back(it->second);
	}
	left.insert(left.begin(), *right.begin());
	size_t	jacobsthal = 0;
	size_t	count = 1;
	for (int power = 1; count < half; ++power)
	{
		jacobsthal = (1 << power) - jacobsthal;
		if (count + jacobsthal > half)
			jacobsthal = half - count;
		for (size_t i = jacobsthal; i > 0; --i)
		{
			std::list<int>::iterator	position
			left.insert(binarySearch(left.begin(), pickListElement(left, 2 * (count + jacobsthal) - 1 - i), pickListElement(right, count + i - 1))
						,pickListElement(right, count + i - 1));
		}
		count += jacobsthal;
	}
	if (odd_size)
		left.insert(std::lower_bound(left.begin(), left.end(), _datal[_datal.size() - 1]), _datal[_datal.size() - 1]);
	_datal = left;
}*/

/*void	PmergeMe::sortList(void)
{
	size_t								half = (_datal.size() / 2);
	bool								odd_size = _datal.size() % 2;
	std::list< std::pair<int, int> >	data_pairs;
	std::list<int>					left;
	std::list<int>					right;
	for (std::list<int>::iterator it = _datal.begin(); it != _datal.end(); it += 2)
	{
		if (it + 1 == _datal.end())
			break;
		if (*it > *(it + 1))
			data_pairs.push_back(std::make_pair(*it, *(it + 1)));
		else
			data_pairs.push_back(std::make_pair(*(it + 1), *it));
	}
	std::sort(data_pairs.begin(), data_pairs.end(), compareByFirst);
	for (std::list< std::pair<int, int> >::iterator it = data_pairs.begin(); it != data_pairs.end(); ++it)
	{
		left.push_back(it->first);
		right.push_back(it->second);
	}
	left.insert(left.begin(), *right.begin());
	size_t	jacobsthal = 0;
	size_t	count = 1;
	for (int power = 1; count < half; ++power)
	{
		jacobsthal = (1 << power) - jacobsthal;
		if (count + jacobsthal > half)
			jacobsthal = half - count;
		for (size_t i = jacobsthal; i > 0; --i)
			left.insert(std::lower_bound(left.begin(), left.begin() + 2 * (count + jacobsthal) - 1 - i,
						*(right.begin() + count + i - 1)), *(right.begin() + count + i - 1));
		count += jacobsthal;
	}
	if (odd_size)
		left.insert(std::lower_bound(left.begin(), left.end(), _datal.back()), _datal.back());
	_datal = left;
}*/

/*void	PmergeMe::sortList(void)
{
	size_t								half = (_datal.size() / 2);
	bool								odd_size = _datal.size() % 2;
	std::list< std::pair<int, int> >	data_pairs;
	std::list<int>					left;
	std::list<int>					right;
	for (size_t i = 0; i < half; ++i)
	{
		std::list<int>::iterator	it = _datal.begin() + (2 * i);
		if (*it > *(it + 1))
			data_pairs.push_back(std::make_pair(*it, *(it + 1)));
		else
			data_pairs.push_back(std::make_pair(*(it + 1), *it));
	}
	std::sort(data_pairs.begin(), data_pairs.end(), compareByFirst);
	for (size_t i = 0; i < half; ++i)
	{
		left.push_back((data_pairs.begin() + i)->first);
		right.push_back((data_pairs.begin() + i)->second);
	}
	left.insert(left.begin(), right[0]);
	size_t	jacobsthal = 0;
	size_t	count = 1;
	for (int power = 1; count < half; ++power)
	{
		jacobsthal = (1 << power) - jacobsthal;
		if (count + jacobsthal > half)
			jacobsthal = half - count;
		for (size_t i = jacobsthal; i > 0; --i)
			left.insert(std::lower_bound(left.begin(), left.begin() + 2 * (count + jacobsthal) - 1 - i,
						*(right.begin() + count + i - 1)), *(right.begin() + count + i - 1));
		count += jacobsthal;
	}
	if (odd_size)
		left.insert(std::lower_bound(left.begin(), left.end(), *(_datal.begin() + _datal.size() - 1)), *(_datal.begin() + _datal.size() - 1));
	_datal = left;
}*/

/*void	PmergeMe::sortVector(void)
{
	size_t								half = (_datav.size() / 2);
	bool								odd_size = _datav.size() % 2;
	std::vector< std::pair<int, int> >	data_pairs;
	std::vector<int>					left;
	std::vector<int>					right;
	for (size_t i = 0; i < half; ++i)
	{
		if (_datav[2 * i] > _datav[(2 * i) + 1])
			data_pairs.push_back(std::make_pair(_datav[2 * i], _datav[(2 * i) + 1]));
		else
			data_pairs.push_back(std::make_pair(_datav[(2 * i) + 1], _datav[2 * i]));
	}
	std::sort(data_pairs.begin(), data_pairs.end(), compareByFirst);
	for (size_t i = 0; i < half; ++i)
	{
		left.push_back(data_pairs[i].first);
		right.push_back(data_pairs[i].second);
	}
	left.insert(left.begin(), right[0]);
	size_t	jacobsthal = 0;
	size_t	count = 1;
	for (int power = 1; count < half; ++power)
	{
		jacobsthal = (1 << power) - jacobsthal;
		if (count + jacobsthal > half)
			jacobsthal = half - count;
		for (size_t i = jacobsthal; i > 0; --i)
			left.insert(std::lower_bound(left.begin(), left.begin() + 2 * (count + jacobsthal) - 1 - i, right[count + i - 1]), right[count + i - 1]);
		count += jacobsthal;
	}
	if (odd_size)
		left.insert(std::lower_bound(left.begin(), left.end(), _datav[_datav.size() - 1]), _datav[_datav.size() - 1]);
	_datav = left;
}
*/

/*void	PmergeMe::sortDeque(void)
{
	size_t								half = (_datad.size() / 2);
	bool								odd_size = _datad.size() % 2;
	std::deque< std::pair<int, int> >	data_pairs;
	std::deque<int>					left;
	std::deque<int>					right;
	for (size_t i = 0; i < half; ++i)
	{
		if (_datad[2 * i] > _datad[(2 * i) + 1])
			data_pairs.push_back(std::make_pair(_datad[2 * i], _datad[(2 * i) + 1]));
		else
			data_pairs.push_back(std::make_pair(_datad[(2 * i) + 1], _datad[2 * i]));
	}
	std::sort(data_pairs.begin(), data_pairs.end(), compareByFirst);
	for (size_t i = 0; i < half; ++i)
	{
		left.push_back(data_pairs[i].first);
		right.push_back(data_pairs[i].second);
	}
	left.insert(left.begin(), right[0]);
	size_t	jacobsthal = 0;
	size_t	count = 1;
	for (int power = 1; count < half; ++power)
	{
		jacobsthal = (1 << power) - jacobsthal;
		if (count + jacobsthal > half)
			jacobsthal = half - count;
		for (size_t i = jacobsthal; i > 0; --i)
			left.insert(std::lower_bound(left.begin(), left.begin() + 2 * (count + jacobsthal) - 1 - i, right[count + i - 1]), right[count + i - 1]);
		count += jacobsthal;
	}
	if (odd_size)
		left.insert(std::lower_bound(left.begin(), left.end(), _datad[_datad.size() - 1]), _datad[_datad.size() - 1]);
	_datad = left;
}*/

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
