/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClosedBrackets.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:08:18 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 15:08:47 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSEDBRACKETS_HPP
#define CLOSEDBRACKETS_HPP

#include "Instruction.hpp"

class ClosedBrackets : public Instruction {

public:
    ClosedBrackets();
    ~ClosedBrackets();
    ClosedBrackets(ClosedBrackets const &);
    ClosedBrackets const & operator=(ClosedBrackets const &);

    void execute(MOContainer & container);
};

#endif