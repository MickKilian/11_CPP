/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:53:28 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/21 18:38:40 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA
# define A_MATERIA

#include <string.h>
#include <iostream.h>

class AMateria {

	public:
		AMateria( void );
		AMateria( const AMateria& original );
		AMateria( const std::string& type );
		~AMateria( void );
		AMateria& operator=( const AMateria& original );
		std::string const &	getType( void ) const; //Returns the materia type
		virtual AMateria*	clone( void ) const = 0;
		virtual void		use( ICharacter& target );
	
	protected:
		std::string	_type;
};

#endif // A_MATERIA
