/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:57:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/16 01:34:55 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE
# define ICE

#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice( void );
		Ice ( const Ice& original );
		~Ice( void );
		Ice& operator=( const Ice& original );
		AMateria*	clone( void ) const;
};

#endif // ICE
