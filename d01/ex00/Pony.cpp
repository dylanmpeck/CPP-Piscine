/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:45:02 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 14:05:35 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony() : _name("Pony"), _color("Black"), _trait("Brave") {}

Pony::Pony(std::string name, std::string color, std::string trait) : 
            _name(name), _color(color), _trait(trait) {}

Pony::~Pony()
{
    std::cout << this->_name << " deleting now. Goodbye!" << std::endl;
}

std::string const Pony::getName()
{
    return (this->_name);
}

std::string const Pony::getColor()
{
    return (this->_color);
}

std::string const Pony::getTrait()
{
    return (this->_trait);
}