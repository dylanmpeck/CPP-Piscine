/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenBrackets.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:06:44 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 15:08:08 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenBrackets.hpp"

OpenBrackets::OpenBrackets() {}

OpenBrackets::~OpenBrackets() {}

OpenBrackets::OpenBrackets(OpenBrackets const & other) { *this = other; }

OpenBrackets const & OpenBrackets::operator=(OpenBrackets const & rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

void OpenBrackets::execute(MOContainer & container)
{
    //shouldn't be executed. OpenBracket class will be used to recognize an open bracket in vector.
    static_cast<void>(container);
    return;
}