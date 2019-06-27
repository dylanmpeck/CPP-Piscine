/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrementByteAtPointer.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:21:14 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 15:43:17 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IncrementByteAtPointer.hpp"

IncrementByteAtPointer::IncrementByteAtPointer() {}

IncrementByteAtPointer::~IncrementByteAtPointer() {}

IncrementByteAtPointer::IncrementByteAtPointer(IncrementByteAtPointer const & other) { *this = other; }

IncrementByteAtPointer const & IncrementByteAtPointer::operator=(IncrementByteAtPointer const & rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

void IncrementByteAtPointer::execute(MOContainer & container)
{
    char *dataAtCurPos = container.getDataAtCurPos();
    *dataAtCurPos += 1;
}