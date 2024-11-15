/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:42:21 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/15 02:06:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H

# include <stack>
# include <iostream>

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define CYAN			"\x1b[36m"
# define RESET			"\x1b[0m"

template < typename T, class Container = std::deque<T> >
class	MutantStack : public std::stack< T, Container >
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack &other) : std::stack< T, Container >(other) {
			std::cout << CYAN << "Calling copy constructor" << RESET << std::endl;
		}
		~MutantStack() {}

		MutantStack				&operator=(const MutantStack &other)
		{
			std::cout << CYAN << "Calling assignment operator" << RESET << std::endl;
			std::stack< T, Container >::operator=(other);
			return (*this);
		}

		typedef typename Container::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

#endif
