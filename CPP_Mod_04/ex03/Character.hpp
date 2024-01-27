/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:40:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/17 06:16:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define NB_MAX_MATERIA 4

class Character : public ICharacter {
	public:
		Character( void );
		Character( const std::string & );
		Character( const Character & );
		~Character( void );
		Character& operator=( const Character & );
		std::string const &	getName( void ) const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );

	private:
		std::string			_name;
		AMateria*			_inventory[NB_MAX_MATERIA];
};

#endif // CHARACTER_H
