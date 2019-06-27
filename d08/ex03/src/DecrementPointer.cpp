/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrementPointer.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:19:28 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:19:59 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DecrementPointer.hpp"

DecrementPointer::DecrementPointer() {}

DecrementPointer::~DecrementPointer() {}

DecrementPointer::DecrementPointer(DecrementPointer const & other) { *this = other; }

DecrementPointer const & DecrementPointer::operator=(DecrementPointer const & rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

void DecrementPointer::execute(MOContainer & container)
{
    container.setPosition(container.getPosition() - 1);

    if (container.getPosition() < 0)
        throw(std::exception());   
}