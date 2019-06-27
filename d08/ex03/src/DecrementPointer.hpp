/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrementPointer.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:18:39 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:48:04 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECREMENTPOINTER_HPP
#define DECREMENTPOINTER_HPP

#include "Instruction.hpp"

class DecrementPointer : public Instruction {

public:
    DecrementPointer();
    ~DecrementPointer();
    DecrementPointer(DecrementPointer const &);
    DecrementPointer const & operator=(DecrementPointer const &);

    void execute(MOContainer & container);
};

#endif