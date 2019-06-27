/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:52:29 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 17:26:58 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _iq(0) {}

Brain::Brain(int iq) : _iq(iq) {}

Brain::~Brain() {}

std::string Brain::identify() const
{
    const void *address = static_cast<const void *>(this);
    std::stringstream ss;
    ss << address;
    return (ss.str());
}

int Brain::getIq()
{
    return (this->_iq);
}