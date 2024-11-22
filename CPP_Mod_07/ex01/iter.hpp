/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:24:41 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/11/22 15:47:00 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define YELLOW			"\x1b[33m"
#define RESET			"\x1b[0m"

template <typename T>
void	iter(T *arr, std::size_t size, void (* func)(const T &))
{
	if (!arr || size == 0 || !func)
		return;
	for (std::size_t i = 0; i < size; ++i)
		func(arr[i]);
}
