#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cmath>

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

std::vector<int>::iterator	binarySearch(std::vector<int>::iterator begin, std::vector<int>::iterator end, int elem_search, int nb_elem)
{
	std::vector<int>::iterator	pos = begin;
	if (std::distance(begin, end) == 0)
		return (pos);
	std::vector<int>::iterator	mid = begin + (std::distance(begin, end) / nb_elem / 2) * nb_elem;
	//std::cout << "res calc = " << (std::distance(begin, end) / nb_elem / 2) * nb_elem << std::endl;
	//std::cout << CYAN << "elem_search : " << elem_search << RESET << std::endl;
	//std::cout << RED << "bound : " << *(end + nb_elem - 1) << RESET << std::endl;
	//std::cout << RESET << "  elem_beg : " << *(begin) << RESET << std::endl;
	//std::cout << RESET << "  elem_end : " << *(end) << RESET << std::endl;
	//std::cout << RESET << "  elem_mid : " << *(mid + nb_elem - 1) << RESET << std::endl;
	++comp_k;
	std::cout << WHITE << "-> Comparing : " << elem_search << " with " << *(mid + nb_elem - 1) << RESET << std::endl;
	if (elem_search < *(mid + nb_elem - 1))
		pos = binarySearch(begin, mid, elem_search, nb_elem);
	else
		pos = binarySearch(mid + nb_elem, end, elem_search, nb_elem);
	return (pos);
}

void	insertRange(std::vector<int> &vec, std::vector<int>::iterator pos, std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	vec.insert(pos, start, end);
}

std::vector<int>	fordJohnsonInsertion(std::vector<int> sequence, int level)
{
	int					count = 0;
	int					nb_elem = pow(2, level - 1);
	std::cout << YELLOW << "** Inst level_" << level << " : ";
	printSeq(sequence, level);
	//std::cout << MAGENTA << "nb_elem : " << nb_elem << RESET << std::endl;
	int	nb_as = sequence.size() / (2 * nb_elem);
	int	nb_bs = sequence.size() / (2 * nb_elem) + (sequence.size() - (sequence.size() / (2 * nb_elem) * (2 * nb_elem))) / nb_elem;
	//std::cout << MAGENTA << "nb_as : " << nb_as << ", nb_bs : " << nb_bs << RESET << std::endl;
	//generate main_seq
	//add b1 to main_seq
	std::vector<int>	main_seq;
	insertRange(main_seq, main_seq.begin(), sequence.begin(), sequence.begin() + nb_elem);
	//add as to main_seq
	for (int i = 0; i < nb_as; ++i)
		insertRange(main_seq, main_seq.end(), sequence.begin() + (2 * i + 1) * nb_elem, sequence.begin() + (2 * (i + 1)) * nb_elem);
	//insert bs using jacobsthal
	//std::cout << WHITE << "jacobsthal generate for n = " << nb_as << std::endl;
	std::vector<int>	jacobsthalIndices = generateJacobsthalSequence(nb_as);
	//std::cout << WHITE << "jacobsthal indices : ";
	//printVec(jacobsthalIndices);
	std::cout << MAGENTA << "** b1+as        : " << RESET;
	printVec(main_seq);
	if (nb_as > 1)
	{
		int temp = 1;
		for (int j = 1; j < jacobsthalIndices.size(); ++j)
		{
			//std::cout << "j = " << j << std::endl;
			for (int i = jacobsthalIndices[j]; i > temp; --i)
			{
				//std::cout << "i_jacob = " << i << std::endl;
				if (i > nb_as)
					continue;
				std::cout << CYAN << "search b" << "[" << i << "] = " << *(sequence.begin() + (2 * i - 1) * nb_elem - 1) << RESET << std::endl;
				std::cout << RED << "bound : " << *(main_seq.begin() + (i + 1 + count) * nb_elem - 1) << RESET << std::endl;
				std::vector<int>::iterator	pos = binarySearch(main_seq.begin(), main_seq.begin() + (i + count) * nb_elem, *(sequence.begin() + (2 * i - 1) * nb_elem - 1), nb_elem);
				std::cout << WHITE << "found : " << *(pos + nb_elem - 1) << RESET << std::endl;
				insertRange(main_seq, pos, sequence.begin() + (2 * i - 2) * nb_elem, sequence.begin() + (2 * i - 1) * nb_elem);
				std::cout << MAGENTA << "** adding_bi    : " << RESET;
				printVec(main_seq);
				++count;
			}
			temp = jacobsthalIndices[j];
		}
		/*for (int i = nb_as; i > temp; --i)
		{
			//std::cout << "i_jacob = " << i << std::endl;
			std::cout << CYAN << "search b" << "[" << i << "] = " << *(sequence.begin() + (2 * i - 1) * nb_elem - 1) << RESET << std::endl;
			std::cout << RED << "bound : " << *(main_seq.begin() + (i + 1 + count) * nb_elem - 1) << RESET << std::endl;
			std::vector<int>::iterator	pos = binarySearch(main_seq.begin(), main_seq.begin() + (i + count) * nb_elem, *(sequence.begin() + (2 * i - 1) * nb_elem - 1), nb_elem);
			std::cout << WHITE << "found : " << *(pos + nb_elem - 1) << RESET << std::endl;
			insertRange(main_seq, pos, sequence.begin() + (2 * i - 2) * nb_elem, sequence.begin() + (2 * i - 1) * nb_elem);
			std::cout << MAGENTA << "** adding_bi    : " << RESET;
			printVec(main_seq);
			++count;
		}*/
	}

	//insert last b if there is one
	if (nb_as != nb_bs)
	{
		int i = nb_bs;
		std::cout << CYAN << "search b" << "[" << i << "] = " << *(sequence.begin() + (2 * i - 1) * nb_elem - 1) << RESET << std::endl;
		std::cout << RED << "bound : END" << RESET << std::endl;
		std::vector<int>::iterator	pos = binarySearch(main_seq.begin(), main_seq.end(), *(sequence.begin() + (2 * i - 1) * nb_elem - 1), nb_elem);
		std::cout << WHITE << "found : " << *(pos - nb_elem + 1) << RESET << std::endl;
		insertRange(main_seq, pos, sequence.begin() + (2 * i - 2) * nb_elem, sequence.begin() + (2 * i - 1) * nb_elem);
		std::cout << MAGENTA << "** adding_odd_b : " << RESET;
		printVec(main_seq);
	}
	//add odd elements
	for (std::vector<int>::iterator it = sequence.begin() + nb_as * 2 * nb_elem + (nb_bs - nb_as) * nb_elem; it != sequence.end(); ++it)
	{
		main_seq.push_back(*it);
	}
	std::cout << MAGENTA << "** adding_odds  : " << RESET;
	printVec(main_seq);
	return (main_seq);
}

std::vector<int>	fordJohnsonSort(std::vector<int> sequence, int level)
{
	int					count = 0;
	int					nb_elem = pow(2, level - 1);

	for (std::vector<int>::iterator it = sequence.begin(); it != sequence.end(); it += 2 * nb_elem)
	{
		count += 2 * nb_elem;
		if (count > sequence.size())
			break;
		++comp_k;
		std::cout << WHITE << "-> Comparing : " << *(it + nb_elem - 1) << " with " << *(it + (2 * nb_elem) - 1) << RESET << std::endl;
		if (*(it + nb_elem - 1) > *(it + (2 * nb_elem) - 1))
			for (int i = 0; i < nb_elem; ++i)
			{
				std::swap(*(it + i), *(it + nb_elem + i));
			}
	}
	std::cout << YELLOW << "** Sort level_" << level << " : ";
	printSeq(sequence, level);
	if (2 * pow(2, level) <= sequence.size())
		sequence = fordJohnsonSort(sequence, level + 1);
	sequence = fordJohnsonInsertion(sequence, level);
	return (sequence);
}

int	computeMaxComparisons(int n)
{
	int	ret = 0;

	for (int i = 1; i < n + 1; ++i)
	{
		double	log_val = std::ceil(std::log(3.0 * (double)i / 4.0) / std::log(2));
    	ret += log_val;
	}
	return ret;
}

int	main(int ac, char *av[])
{
	std::vector<int>	sequence;
	if (ac < 3)
	{
		std::cout << "Usage: ./PmergeMe [list of at least two positive integers]" << std::endl;
		return 0;
	}
	sequence = parseData(av, ac - 1);
	std::cout << YELLOW << "  Input ";
	printVec(sequence);
	sequence = fordJohnsonSort(sequence, 1);
	std::cout << RESET << std::endl;
	std::cout << YELLOW << "  Final ";
	printVec(sequence);
	checkOrdered(sequence);
	std::cout << MAGENTA << "  theoretical max_comparisons = " << computeMaxComparisons(ac - 1) << RESET << std::endl;
	std::cout << GREEN << "your program's nb_comparisons = " << comp_k << (comp_k <= computeMaxComparisons(ac - 1) ? GREEN " OK" : RED " NOK") << RESET << std::endl;
	return 0;
}
