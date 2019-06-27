/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:26:20 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:27:59 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon {

private:
    std::string _name;
    int _apCost;
    int _damagePower;

protected:
    AWeapon();

public:
    AWeapon(std::string const & name, int apcost, int damage);
    virtual ~AWeapon();
    AWeapon(AWeapon const &);
    AWeapon & operator=(AWeapon const &);

    std::string const & getName() const;
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;
};

#endif
