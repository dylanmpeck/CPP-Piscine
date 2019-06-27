/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:07:09 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:42:15 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::~PowerFist() {}

PowerFist::PowerFist(PowerFist const & other) : AWeapon(other)
{
    *this = other;
}

PowerFist::PowerFist(AWeapon const & other) : AWeapon(other)
{
	*this = other;
}

PowerFist & PowerFist::operator=(PowerFist const & rhs)
{
	if (this == &rhs)
		return (*this);

    AWeapon::operator=(rhs);

    return (*this);
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
