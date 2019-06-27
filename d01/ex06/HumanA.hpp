/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:19:18 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 19:00:38 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

private:
    Weapon& _weapon;
    std::string _name;

public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();

    void attack();
};

#endif