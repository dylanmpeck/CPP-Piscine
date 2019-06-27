/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:11:21 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 15:19:35 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : _hp(0), _type("DEFAULT TYPE") {}

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type) {}

Enemy::~Enemy() {}

Enemy::Enemy(Enemy const & other)
{
    *this = other;
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this == &rhs)
		return (*this);

    this->_hp = rhs._hp;
    this->_type = rhs._type;

    return (*this);
}

std::string const & Enemy::getType() const
{
    return (this->_type);
}

int Enemy::getHP() const
{
    return (this->_hp);
}

void Enemy::takeDamage(int damage)
{
    if (damage > 0)
    {
        if (this->_hp - damage <= 0)
            this->_hp = 0;
        else
            this->_hp -= damage;
    }
}
