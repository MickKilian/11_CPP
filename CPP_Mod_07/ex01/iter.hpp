/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:24:41 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/10/31 21:13:45 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	iter(T *arr, std::size_t size, void (* func)(const T &))
{
	if (!arr || size == 0 || !func)
		return;
	for (std::size_t i = 0; i < size; ++i)
		func(arr[i]);
}
