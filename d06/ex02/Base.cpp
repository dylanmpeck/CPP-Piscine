/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:55:55 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 13:55:58 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base() {}

Base::~Base() {}

Base const & Base::operator=(Base const & rhs)
{
    static_cast<void>(rhs);
    return *this;
}

Base::Base(Base const & other)
{
    *this = other;
}
