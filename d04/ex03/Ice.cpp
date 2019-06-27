/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:29:24 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 12:33:09 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(Ice const & other)
{
    *this = other;
}

Ice const & Ice::operator=(Ice const & rhs)
{
	if (this == &rhs)
		return (*this);

    this->setXP(rhs.getXP());
    
    return (*this);
}

AMateria * Ice::clone() const
{
    Ice *clone = new Ice();
    clone->setXP(this->getXP());
    return (clone);
}
