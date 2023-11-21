/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:43:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:40 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER.H
#define I_CHARACTER.H

#include "AMateria.hpp"
#include "string.h"

class ICharacter {
	public:
		virtual ~ICharacter() {}
		virtual std::string const &	getName() const = 0;
		virtual void				equip( AMateria* m ) = 0;
		virtual void				unequip( int idx ) = 0;
		virtual void				use( int idx, ICharacter& target ) = 0;
};

#endif //I_CHARACTER
