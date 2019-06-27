/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrementPointer.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:08:50 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:48:04 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCREMENTPOINTER_HPP
#define INCREMENTPOINTER_HPP

#include "Instruction.hpp"

class IncrementPointer : public Instruction {

public:
    IncrementPointer();
    ~IncrementPointer();
    IncrementPointer(IncrementPointer const &);
    IncrementPointer const & operator=(IncrementPointer const &);

    void execute(MOContainer & container);
};

#endif