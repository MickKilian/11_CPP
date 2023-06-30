/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:27:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 14:33:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main( void ) {
	std::string	message("HI THIS IS BRAIN");
	std::string	*stringPTR = &message;
	std::string	&stringREF = message;

	std::cout << "Addresse de la string : " << &message << std::endl;
	std::cout << "Addresse stockee dans stringPTR : " << stringPTR << std::endl;
	std::cout << "Addresse stockee dans stringREF : " << &stringREF << std::endl;
	std::cout << "Valeur de la string : " << message << std::endl;
	std::cout << "Valeur pointee par stringPTR : " << *stringPTR << std::endl;
	std::cout << "Valeur pointee par stringPREF : " << stringREF << std::endl;
}
