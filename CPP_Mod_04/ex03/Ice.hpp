/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:57:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/17 05:27:33 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice( void );
		Ice ( const Ice & );
		~Ice( void );

		Ice& operator=( const Ice & );
		AMateria*	clone( void ) const;
		void		use( ICharacter& target );
};

#endif // ICE_H
