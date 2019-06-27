/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:25:21 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 15:48:37 by dpeck            ###   ########.fr       */
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

std::string const Zombie::getName()
{
    return (this->_name);
}

std::string const Zombie::getType()
{
    return (this->_type);
}