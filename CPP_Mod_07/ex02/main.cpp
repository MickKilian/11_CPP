/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:34:55 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/31 23:43:18 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
void	ft_print(const Array<T> &arr)
{
	try
	{
		for (std::size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i];
			if (i < arr.size() - 1)
				std::cout << " | ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;

	}
}

template <typename T>
void unit_test(int size, T arg1, T arg2)
{
	std::cout << YELLOW << "PARAMETRIC CONSTRUCTOR" << RESET << std::endl;
	Array<T> arr(size);
	std::cout << "Array of size : " << arr.size() << std::endl;
	std::cout << YELLOW << "ARRAY ASSIGNMENT" << RESET << std::endl;
	for (std::size_t i = 0; i < arr.size(); ++i)
	{
			arr[i] = arg1;
	}
	std::cout << "-> Ok" << std::endl;
	std::cout << YELLOW << "ARRAY DISPLAY" << RESET << std::endl;
	std::cout << "display arr : ";
	ft_print(arr);
	std::cout << YELLOW << "TEST OUT-OF-BOUND index : " << RESET << "-1" << std::endl;
	try
	{
		arr[-1];
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << YELLOW << "TEST OUT-OF-BOUND index : " << RESET << arr.size() << std::endl;
	try
	{
		arr[arr.size()];
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << YELLOW << "COPY CONSTRUCTOR" << RESET << std::endl;
	Array<T> arr_cpy(arr);
	std::cout << "source of size : " << arr.size() << std::endl;
	std::cout << "display source : ";
	ft_print(arr);
	std::cout << "copy of size : " << arr_cpy.size() << std::endl;
	std::cout << "display copy : ";
	ft_print(arr_cpy);
	std::cout << YELLOW << "----> Modify 2nd element of source" << RESET << std::endl;
	arr[1] = arg2;
	std::cout << "display source : ";
	ft_print(arr);
	std::cout << "display copy : ";
	ft_print(arr_cpy);
	std::cout << YELLOW << "----> Modify 3rd element of copy" << RESET << std::endl;
	arr_cpy[2] = arg2;
	std::cout << "display source : ";
	ft_print(arr);
	std::cout << "display copy : ";
	ft_print(arr_cpy);
	std::cout << YELLOW << "ASSIGNMENT OPERATOR" << RESET << std::endl;
	arr[1] = arg1;
	std::cout << "source of size : " << arr.size() << std::endl;
	std::cout << "display source : ";
	ft_print(arr);
	Array<T> arr_assignment;
	arr_assignment = arr;
	std::cout << "copy of size : " << arr_assignment.size() << std::endl;
	std::cout << "display copy : ";
	ft_print(arr_cpy);
	std::cout << YELLOW << "----> Modify 2nd element of source" << RESET << std::endl;
	arr[1] = arg2;
	std::cout << "display source : ";
	ft_print(arr);
	std::cout << "display copy : ";
	ft_print(arr_assignment);
	std::cout << YELLOW << "----> Modify 3rd element of copy" << RESET << std::endl;
	arr_assignment[2] = arg2;
	std::cout << "display source : ";
	ft_print(arr);
	std::cout << "display copy : ";
	ft_print(arr_assignment);
	std::cout << YELLOW << "DEFAULT CONSTRUCTOR" << RESET << std::endl;
	Array<T> arr_0;
	std::cout << YELLOW << "----> Trying to Access element of index 0" << RESET << std::endl;
	try
	{
		arr_0[0];
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << CYAN << "TEST with int" << RESET << std::endl;
	unit_test<int>(5, 10, 99);
	std::cout << std::endl;
	std::cout << CYAN << "TEST with string" << RESET << std::endl;
	unit_test<std::string>(10, "ok", "change");
	return 0;
}
