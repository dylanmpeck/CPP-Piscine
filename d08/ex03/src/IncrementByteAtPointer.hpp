/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrementByteAtPointer.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:20:27 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:48:04 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCREMENTBYTEATPOINTER_HPP
#define INCREMENTBYTEATPOINTER_HPP

#include "Instruction.hpp"

class IncrementByteAtPointer : public Instruction {

public:
    IncrementByteAtPointer();
    ~IncrementByteAtPointer();
    IncrementByteAtPointer(IncrementByteAtPointer const &);
    IncrementByteAtPointer const & operator=(IncrementByteAtPointer const &);

    void execute(MOContainer & container);
};

#endif