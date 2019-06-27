/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:06:29 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 17:25:04 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() : _brain(Brain()) {}

Human::~Human() {}

Brain const& Human::getBrain()
{
    return (this->_brain);
}

std::string Human::identify()
{
    return (this->_brain.identify());
}