/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:32:11 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 18:10:58 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <ostream>

class Character {

private:
    std::string _name;
    int _ap;
    AWeapon *_weapon;
    Character();

public:
    Character(std::string const & name);
    ~Character();
    Character(Character const &);
    Character & operator=(Character const &);

    void recoverAP();
    void equip(AWeapon*);
    void attack(Enemy*);

    std::string const & getName() const;
    AWeapon const *getWeapon() const;
    int const & getAP() const;
};

std::ostream & operator<<(std::ostream & o, Character const & rhs);

#endif