/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrementPointer.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:10:35 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:18:15 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IncrementPointer.hpp"

IncrementPointer::IncrementPointer() {}

IncrementPointer::~IncrementPointer() {}

IncrementPointer::IncrementPointer(IncrementPointer const & other) { *this = other; }

IncrementPointer const & IncrementPointer::operator=(IncrementPointer const & rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

void IncrementPointer::execute(MOContainer & container)
{
    container.setPosition(container.getPosition() + 1);

    if (container.getPosition() > container._size)
        throw(std::exception());   
}