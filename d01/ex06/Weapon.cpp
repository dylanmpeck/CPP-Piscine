/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:15:30 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 18:22:26 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("") {}

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

std::string const & Weapon::getType()
{
    return (this->_type);
}