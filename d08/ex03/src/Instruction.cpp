/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:07:04 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:08:35 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instruction.hpp"

Instruction::Instruction() {}

Instruction::~Instruction() {}

Instruction::Instruction(Instruction const & other) { *this = other; }

Instruction const & Instruction::operator=(Instruction const & rhs)
{
    static_cast<void>(rhs);
    return (*this);
}