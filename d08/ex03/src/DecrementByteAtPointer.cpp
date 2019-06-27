/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrementByteAtPointer.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:24:15 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 15:42:57 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DecrementByteAtPointer.hpp"

DecrementByteAtPointer::DecrementByteAtPointer() {}

DecrementByteAtPointer::~DecrementByteAtPointer() {}

DecrementByteAtPointer::DecrementByteAtPointer(DecrementByteAtPointer const & other) { *this = other; }

DecrementByteAtPointer const & DecrementByteAtPointer::operator=(DecrementByteAtPointer const & rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

void DecrementByteAtPointer::execute(MOContainer & container)
{
    char *dataAtCurPos = container.getDataAtCurPos();
    *dataAtCurPos -= 1;
}