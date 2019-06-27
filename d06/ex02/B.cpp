/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:55:31 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 13:55:34 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B() {}

B::~B() {}

B const & B::operator=(const B & rhs)
{
    static_cast<void>(rhs);
    return *this;
}

B::B(B const & other)
{
    *this = other;
}