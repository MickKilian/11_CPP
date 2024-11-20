/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:55:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/18 12:37:52 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define SIZE 100
int	main(void)
{
	std::cout << YELLOW << "TESTS FROM SUBJECT : " << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << GREEN << "top element : " << mstack.top() << RESET << std::endl;
	mstack.pop();
	std::cout << GREEN << "size : " << mstack.size() << RESET << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << YELLOW << "ADDITIONAL TESTS : " << RESET << std::endl;
	std::cout << YELLOW << "Reverse iterators : " << RESET << std::endl;
	MutantStack<int>::reverse_iterator itr = mstack.rbegin();
	MutantStack<int>::reverse_iterator iter = mstack.rend();
	++iter;
	--iter;
	while (itr != iter)
	{
	std::cout << *itr << std::endl;
	++itr;
	}
	std::cout << YELLOW << "Large number for elements : " << RESET << std::endl;
	MutantStack<int> testStack;
	for (int i = 0; i < SIZE; i++)
		testStack.push(i + 1);
	for (MutantStack<int>::iterator it = testStack.begin(); it < testStack.end(); it++)
		std::cout << *it << " | ";

	std::cout << YELLOW << "\nCopy constructor : " << RESET << std::endl;
	MutantStack<int> copyStack(testStack);
	for (MutantStack<int>::iterator it = copyStack.begin(); it < copyStack.end(); it++)
		std::cout << *it << " | ";

	std::cout << YELLOW << "\nAssignment operator : " << RESET << std::endl;
	MutantStack<int> assignStack;
	assignStack = testStack;
	for (MutantStack<int>::iterator it = assignStack.begin(); it < assignStack.end(); it++)
		std::cout << *it << " | ";
	std::cout << std::endl;

	std::cout << RED << "\nTESTS with LIST Container : " << RESET << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << GREEN << "top element : " << mlist.back() << RESET << std::endl;
	mlist.pop_back();
	std::cout << GREEN << "size : " << mlist.size() << RESET << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	std::list<int>::iterator list_it = mlist.begin();
	std::list<int>::iterator list_ite = mlist.end();
	++list_it;
	--list_it;
	while (list_it != list_ite)
	{
	std::cout << *list_it << std::endl;
	++list_it;
	}
	std::list<int> s_list(mlist);

	std::cout << YELLOW << "ADDITIONAL TESTS : " << RESET << std::endl;
	std::cout << YELLOW << "Reverse iterators : " << RESET << std::endl;
	std::list<int>::reverse_iterator list_itr = mlist.rbegin();
	std::list<int>::reverse_iterator list_iter = mlist.rend();
	++list_iter;
	--list_iter;
	while (list_itr != list_iter)
	{
	std::cout << *list_itr << std::endl;
	++list_itr;
	}
	std::cout << YELLOW << "Large number for elements : " << RESET << std::endl;
	std::list<int> testList;
	for (int i = 0; i < SIZE; i++)
		testList.push_back(i + 1);
	for (std::list<int>::iterator it = testList.begin(); it != testList.end(); it++)
		std::cout << *it << " | ";

	std::cout << YELLOW << "\nCopy constructor : " << RESET << std::endl;
	std::list<int> copyList(testList);
	for (std::list<int>::iterator it = copyList.begin(); it != copyList.end(); it++)
		std::cout << *it << " | ";

	std::cout << YELLOW << "\nAssignment operator : " << RESET << std::endl;
	std::list<int> assignList;
	assignList = testList;
	for (std::list<int>::iterator it = assignList.begin(); it != assignList.end(); it++)
		std::cout << *it << " | ";
	std::cout << std::endl;

	return 0;
}
