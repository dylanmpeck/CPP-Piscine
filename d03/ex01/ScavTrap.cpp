/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:55:51 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 21:28:47 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _hitPoints(100), _maxHitPoints(100), _energyPoints(50), _maxEnergyPoints(50),
                        _level(1), _name("Noname"), _meleeAttackDamage(20), _rangedAttackDamage(15), _armorDamageReduction(3)
{
    std::cout << this->_name << ": Watap. I am a scavtrap. Hear me roar!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(50), _maxEnergyPoints(50),
                        _level(1), _name(name), _meleeAttackDamage(20), _rangedAttackDamage(15), _armorDamageReduction(3)
{
    std::cout << this->_name << ": Watap. I am a scavtrap. Hear me roar!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->_name << ": OH NO THIS IS THE END" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & other) : _maxHitPoints(other._maxHitPoints), _maxEnergyPoints(other._maxEnergyPoints)
{
    std::cout << other._name << ": Watap. I am a scavtrap. Hear me roar!" << std::endl;

    *this = other;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other)
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

void ScavTrap::rangedAttack(std::string const & target)
{
    std::cout << "SC4V-TP " << "<" << this->_name << ">";
    std::cout << " shoots its gun at " << target;
    std::cout << " at range, causing " << this->_rangedAttackDamage;
    std::cout << " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "SC4V-TP " << "<" << this->_name << ">";
    std::cout << " blitzes " << target;
    std::cout << " at melee, causing " << this->_meleeAttackDamage;
    std::cout << " points of damage !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    int checkAmount = amount;
    if (checkAmount < 0)
        amount = 0;
    int damage = amount - this->_armorDamageReduction;
    if (damage < 0)
        damage = 0;
    int newHP = this->_hitPoints - damage;

    std::cout << "SC4V-TP " << "<" << this->_name << ">";
    std::cout << " takes " << amount << " points of damage";
    std::cout << " reduced by " << this->_armorDamageReduction << " for a total of ";
    std::cout << damage << " points!" << std::endl;

    if (newHP >= 0)
         this->_hitPoints = newHP;
    else
        this->_hitPoints = 0;
    
    std::cout << "Total hp is now: " << this->_hitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    int checkAmount = amount;
    if (checkAmount < 0)
        amount = 0;

    std::cout << "SC4V-TP " << "<" << this->_name << ">";
    std::cout << " is repaired for ";
    std::cout << amount << " hitpoints!" << std::endl;

    int newHP = this->_hitPoints + amount;
    if (newHP <= this->_maxHitPoints)
        this->_hitPoints = newHP;
    else
        this->_hitPoints = this->_maxHitPoints;

    std::cout << "Total hp is now: " << this->_hitPoints << std::endl;
}

void ScavTrap::challengeNewcomer(std::string const & target)
{
    std::string challenges[] = {"You fight like a Dairy Farmer",
                                "I've spoken with apes more polite than you",
                                "This is the END for you, you gutter crawling cur",
                                "There are no words for how disgusting you are.",
                                "You have the manners of a beggar."};
    int challengeIdx = rand() % 5;
    std::cout << challenges[challengeIdx] << " " << target << "!" << std::endl;
}