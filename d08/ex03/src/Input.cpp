/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:27:58 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 16:06:23 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"
#include <iostream>

Input::Input() {}

Input::~Input() {}

Input::Input(Input const & other) { *this = other; }

Input const & Input::operator=(Input const & rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

void Input::execute(MOContainer & container)
{
    char *dataAtCurPos = container.getDataAtCurPos();
    std::cin >> *dataAtCurPos;
}