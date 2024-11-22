/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:18:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/22 16:08:00 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"
#include <iostream>

int main( void ) {
std::cout << YELLOW << "** TESTS with int" << RESET << std::endl;
int a = 2;
int b = 3;
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << YELLOW << "::swap" << RESET << std::endl;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << YELLOW << "::min" << RESET << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << YELLOW << "::max" << RESET << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::cout << YELLOW << "** TESTS with string" << RESET << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << YELLOW << "::swap" << RESET << std::endl;
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << YELLOW << "::min" << RESET << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << YELLOW << "::max" << RESET << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
