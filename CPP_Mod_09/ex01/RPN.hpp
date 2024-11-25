/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:51:15 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/25 01:42:16 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_P_N_H
# define R_P_N_H

# include <iostream>
# include <string>
# include <sstream>
# include <cctype>
# include <stack>

#define RED				"\x1b[31m"
#define GREEN			"\x1b[32m"
#define YELLOW			"\x1b[33m"
#define RESET			"\x1b[0m"

class RPN
{
	private:
		std::stack<int>	_data;

	public:
		RPN();
		RPN(const RPN &);
		~RPN();

		RPN &operator=(const RPN &);

		void	evaluate(const std::string &);
		void	compute(int);

	class InvalidExpressionException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error");
			}
	};
};

#endif
