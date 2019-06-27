/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenBrackets.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:06:26 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 15:35:31 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instruction.hpp"

class OpenBrackets : public Instruction {

public:
    OpenBrackets();
    ~OpenBrackets();
    OpenBrackets(OpenBrackets const &);
    OpenBrackets const & operator=(OpenBrackets const &);

    void execute(MOContainer & container);
};