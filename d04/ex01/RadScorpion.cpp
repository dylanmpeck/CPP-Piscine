/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:28:08 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 15:20:22 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & other) : Enemy(other)
{
    *this = other;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & rhs)
{
	if (this == &rhs)
		return (*this);

    Enemy::operator=(rhs);

    return (*this);
}
