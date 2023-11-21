/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:33:16 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:19 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE
# define I_MATERIA_SOURCE

#include "AMateria.hpp")

class IMateriaSource {
	public:
		virtual	~IMateriaSource( void ) {}
		virutal void	learn:ateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif I_MATERIA_SOURCE.H
