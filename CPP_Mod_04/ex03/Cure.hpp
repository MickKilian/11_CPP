/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:54:46 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/21 15:42:13 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE
# define CURE

#include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure( void );
		Cure ( const Cure& original );
		~Cure( void );
		Cure& operator=( const Cure& original );
		AMateria*	clone( void ) const;
		void		use( ICharacter& target );
};

#endif // CURE
