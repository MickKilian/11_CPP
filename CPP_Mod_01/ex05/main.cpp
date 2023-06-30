/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:52:08 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/04/30 17:33:31 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl	comment;

	comment.complain("DEBUG");
	comment.complain("INFO");
	comment.complain("OTHER");
	comment.complain("END");
	comment.complain("WARNING");
	comment.complain("ERROR");
	comment.complain("ERROR");
	comment.complain("WARNING");
	comment.complain("CLAIM");
	return 0;
}
