/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:25:21 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 16:17:00 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name(""), _type("") {}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {}

Zombie::~Zombie()
{
    std::cout << this->_name << " deleting." << std::endl;
}

void Zombie::announce()
{
    std::cout << "<" << this->_name << " (" << this->_type << ")> ";
    std::cout << "Braiiiiiiinnnssss..." << std::endl;
}

std::string Zombie::getName()
{
    return (this->_name);
}

std::string Zombie::getType()
{
    return (this->_type);
}

void Zombie::setName(std::string const name)
{
    this->_name = name;
}

void Zombie::setType(std::string const type)
{
    this->_type = type;
}