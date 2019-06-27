/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Output.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:25:12 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:25:47 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "Instruction.hpp"

class Output : public Instruction {

public:
    Output();
    ~Output();
    Output(Output const &);
    Output const & operator=(Output const &);

    void execute(MOContainer & container);
};

#endif