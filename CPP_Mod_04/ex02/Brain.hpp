/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:13:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/15 23:14:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

#define NB_IDEAS 100

#define RED				"\x1b[31m"
#define GREEN			"\x1b[32m"
#define CYAN			"\x1b[36m"
#define YELLOW			"\x1b[33m"
#define BLUE			"\x1b[34m"
#define WHITE			"\x1b[37m"
#define BOLDWHITE		"\x1b[37;1m"
#define RESET			"\x1b[0m"

class Random {
	public:
		typedef unsigned long size_type;
		static size_type generate(void);
		static size_type generate(size_type max);

	private:
		static Random& shared(void);
		size_type generate_impl(void);
		Random(void);
};

class Brain {
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain	&operator=(const Brain &other);
		void	getIdea(int index) const;

	private:
		std::string	_ideas[NB_IDEAS];
};

#endif //BRAIN
