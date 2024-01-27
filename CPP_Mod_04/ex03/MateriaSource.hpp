/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:30:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/17 06:29:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_H
# define MATERIA_SOURCE_H

# include "IMateriaSource.hpp"

# define NB_MAX_LEARNED 4

class MateriaSource : public IMateriaSource {

	public:

		MateriaSource( void );
		MateriaSource( const MateriaSource & );
		~MateriaSource( void );
		MateriaSource& operator=( const MateriaSource & );

		void			learnMateria( AMateria* );
		AMateria		*createMateria( std::string const & type );
		const AMateria	*getLearnedList( void ) const;


	private:

		AMateria*	_learnedMateria[NB_MAX_LEARNED];
};

#endif // MATERIA_SOURCE_H
