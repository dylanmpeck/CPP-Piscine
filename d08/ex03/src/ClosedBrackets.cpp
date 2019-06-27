/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClosedBrackets.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:08:52 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 15:09:21 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClosedBrackets.hpp"

ClosedBrackets::ClosedBrackets() {}

ClosedBrackets::~ClosedBrackets() {}

ClosedBrackets::ClosedBrackets(ClosedBrackets const & other) { *this = other; }

ClosedBrackets const & ClosedBrackets::operator=(ClosedBrackets const & rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

void ClosedBrackets::execute(MOContainer & container)
{
    //shouldn't be executed. ClosedBracket class will be used to recognize an open bracket in vector.
    static_cast<void>(container);
    return;
}