/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:40:20 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 17:26:56 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>
#include <sstream>

class Brain {

private:
    int _iq;

public:
    Brain();
    Brain(int iq);
    ~Brain();

    std::string identify() const;
    int getIq();
};


#endif