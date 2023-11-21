/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:40:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/21 18:29:50 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER.H
# define CHARACTER.H

#include "ICharacter.hpp"

#define NB_MATERIA 4

class Character : public ICharacter {
	public:
		Character( void );
		Character( const std::string& name );
		Character( const Character& original );
		~Character( void );
		Character& operator=( const Character & original );
		std::string const &	getName( void ) const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );

	private:
		std::string			_name;
		AMateria*			_inventaire[4];
};

#endif // CHARACTER.H
