/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrementByteAtPointer.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:22:52 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:23:34 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECREMENTBYTEATPOINTER_HPP
#define DECREMENTBYTEATPOINTER_HPP

#include "Instruction.hpp"

class DecrementByteAtPointer : public Instruction {

public:
    DecrementByteAtPointer();
    ~DecrementByteAtPointer();
    DecrementByteAtPointer(DecrementByteAtPointer const &);
    DecrementByteAtPointer const & operator=(DecrementByteAtPointer const &);

    void execute(MOContainer & container);
};

#endif