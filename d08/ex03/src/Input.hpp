/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:27:14 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:27:54 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
#define INPUT_HPP

#include "Instruction.hpp"

class Input : public Instruction {

public:
    Input();
    ~Input();
    Input(Input const &);
    Input const & operator=(Input const &);

    void execute(MOContainer & container);
};

#endif