/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:18:24 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:06:12 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include "MOContainer.hpp"

class Instruction {

public:
    Instruction();
    virtual ~Instruction();
    Instruction(Instruction const &);
    Instruction const & operator=(Instruction const &);

    virtual void execute(MOContainer & container) = 0;
};

#endif