/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:05:36 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 18:29:13 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {

private:
    std::string _type;

public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();

    void setType(std::string type);
    std::string const & getType();
};

#endif