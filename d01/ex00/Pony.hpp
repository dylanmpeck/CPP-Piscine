/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:40:38 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 14:05:34 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <string>
#include <iostream>

class Pony {

private:
    std::string const _name;
    std::string const _color;
    std::string const _trait;

public:
    Pony();
    Pony(std::string name, std::string color, std::string trait);
    ~Pony();

    std::string const getColor();
    std::string const getName();
    std::string const getTrait();
};

#endif