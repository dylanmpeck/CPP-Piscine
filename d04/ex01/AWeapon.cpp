/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:32:44 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:08:55 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() : _name("DEFAULT NAME"), _apCost(0), _damagePower(0) {}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name), _apCost(apcost), _damagePower(damage)  {}

AWeapon::~AWeapon() {}

AWeapon::AWeapon(AWeapon const & other)
{
    *this = other;
}

AWeapon & AWeapon::operator=(AWeapon const & rhs)
{
	if (this == &rhs)
		return (*this);

    this->_name = rhs._name;
    this->_apCost = rhs._apCost;
    this->_damagePower = rhs._damagePower;

    return (*this);
}

std::string const & AWeapon::getName() const
{
    return (this->_name);
}

int AWeapon::getAPCost() const
{
    return (this->_apCost);
}

int AWeapon::getDamage() const
{
    return (this->_damagePower);
}
