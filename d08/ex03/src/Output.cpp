/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Output.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:26:01 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:27:05 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Output.hpp"
#include <iostream>

Output::Output() {}

Output::~Output() {}

Output::Output(Output const & other) { *this = other; }

Output const & Output::operator=(Output const & rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

void Output::execute(MOContainer & container)
{
    std::cout << *container.getDataAtCurPos();
    std::cout.flush(); 
}