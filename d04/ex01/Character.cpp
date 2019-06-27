/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:38:29 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 15:19:21 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

Character::Character() : _name("DEFAULT NAME"), _ap(0), _weapon(NULL) {}

Character::Character(std::string const & name) : _name(name), _ap(40), _weapon(NULL) {}

Character::~Character() {}

Character::Character(Character const & other)
{
    *this = other;
}

Character & Character::operator=(Character const & rhs)
{
	if (this == &rhs)
		return (*this);

    this->_name = rhs._name;
    this->_ap = rhs._ap;
    this->_weapon = rhs._weapon;

    return (*this);
}

void Character::recoverAP()
{
    this->_ap += 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

void Character::equip(AWeapon *weapon)
{
    this->_weapon = weapon;
}

void Character::attack(Enemy *target)
{
    if (target && this->_weapon != NULL && this->_ap >= this->_weapon->getAPCost())
    {
        std::cout << this->_name << " attacks " << target->getType();
        std::cout << " with a " << this->_weapon->getName() << std::endl;

        this->_weapon->attack();
        target->takeDamage(this->_weapon->getDamage());
        if (target->getHP() <= 0)
            delete target;
        this->_ap -= this->_weapon->getAPCost();
        if (this->_ap < 0)
            this->_ap = 0;
    }
}

AWeapon const *Character::getWeapon() const
{
    return (this->_weapon);
}

std::string const & Character::getName() const
{
    return (this->_name);
}

int const & Character::getAP() const
{
    return (this->_ap);
}

std::ostream & operator<<(std::ostream & o, Character const & rhs)
{
    if (rhs.getWeapon() != NULL)
        o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
    else
        o << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
    return (o);
}
