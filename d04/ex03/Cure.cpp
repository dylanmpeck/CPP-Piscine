/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:28:06 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 12:32:52 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(Cure const & other)
{
    *this = other;
}

Cure const & Cure::operator=(Cure const & rhs)
{
	if (this == &rhs)
		return (*this);

    this->setXP(rhs.getXP());
    
    return (*this);
}

AMateria * Cure::clone() const
{
    Cure *clone = new Cure();
    clone->setXP(this->getXP());
    return (clone);
}
