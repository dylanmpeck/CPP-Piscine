/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:54:19 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 13:57:03 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : ClapTrap(100, 100, 120, 120, 1, "Noname", "SUPER-TP", 60, 20, 5)
{
    std::cout << this->_name << ": It's me. Super mario!" << std::endl;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(100, 100, 120, 120, 1, name, "SUPER-TP", 60, 20, 5)
{
    std::cout << this->_name << ": It's me. Super mario!" << std::endl;
}

SuperTrap::~SuperTrap()
{
    std::cout << this->_name << ": Waaaaaaaaaaaaaaaaaaaaaaah" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & other)
{
    std::cout << other._name << ": It's me. Super Mario!" << std::endl;
    
    *this = other;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & other)
{
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_level = other._level;
    this->_name = other._name;
    this->_meleeAttackDamage = other._meleeAttackDamage;
    this->_rangedAttackDamage = other._rangedAttackDamage;
    this->_armorDamageReduction = other._armorDamageReduction;
    
    return *this;
}

void SuperTrap::rangedAttack(const std::string &target)
{
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(const std::string &target)
{
    NinjaTrap::meleeAttack(target);
}
