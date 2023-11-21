/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:30:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/21 18:46:33 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE.H
# define MATERIA_SOURCE.H

#include "AMateria.hpp"

class MateriaSource : public AMateriaSource {
	public:
		MateriaSource( void );
		MateriaSource( const std::string& original );
		~MateriaSource( void );
		MateraSource& operator=( const std::string& original );
		void		learnMateria( AMateria* m ) = 0;
		AMateria*	createMateria( std::string const & type ) = 0;

	private:
		AMateria*	_newMateria;
}

#endif // MATERIA_SOURCE.H
