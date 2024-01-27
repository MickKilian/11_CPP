/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:53:28 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/26 19:54:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_H
# define A_MATERIA_H

# include <string.h>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

#define RED				"\x1b[31m"
#define GREEN			"\x1b[32m"
#define CYAN			"\x1b[36m"
#define BOLDCYAN		"\x1b[36;1m"
#define YELLOW			"\x1b[33m"
#define MAGENTA			"\x1b[35m"
#define BOLDMAGENTA		"\x1b[35;1m"
#define BLUE			"\x1b[34m"
#define BOLDBLUE		"\x1b[34;1m"
#define WHITE			"\x1b[37m"
#define BOLDWHITE		"\x1b[37;1m"
#define RESET			"\x1b[0m"

class AMateria {

	public:
		AMateria( void );
		AMateria( const AMateria & );
		AMateria( const std::string & );
		virtual ~AMateria( void );

		AMateria& operator=( const AMateria & );
		std::string const	&getType( void ) const; //Returns the materia type
		virtual AMateria	*clone( void ) const = 0;
		virtual void		use( ICharacter &target );
	
	protected:
		std::string	_type;
};

#endif // A_MATERIA_H
