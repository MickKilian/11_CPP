/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:54:46 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/17 05:26:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure( void );
		Cure ( const Cure & );
		~Cure( void );

		Cure& operator=( const Cure & );
		AMateria*	clone( void ) const;
		void		use( ICharacter& target );
};

#endif // CURE_H
