/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:52:51 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 21:23:05 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100), 
                        _level(1), _name("Noname"), _model("CL4P-TP"), _meleeAttackDamage(30), 
                        _rangedAttackDamage(20), _armorDamageReduction(5)
{
    std::cout << "Initializing ClapTrap....." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100), 
                                        _level(1), _name(name), _model("CL4P-TP"), _meleeAttackDamage(30),
                                        _rangedAttackDamage(20), _armorDamageReduction(5)
{
    std::cout << "Initializing ClapTrap...." << std::endl;
}

ClapTrap::ClapTrap(int hitPoints, int const maxHitPoints, int energyPoints, int const maxEnergyPoints, 
                    int level, std::string name, std::string model, int meleeAttackDamage,
                    int rangedAttackDamage, int armorDamageReduction) :
            _hitPoints(hitPoints), _maxHitPoints(maxHitPoints), _energyPoints(energyPoints), _maxEnergyPoints(maxEnergyPoints), 
            _level(level), _name(name), _model(model), _meleeAttackDamage(meleeAttackDamage),
            _rangedAttackDamage(rangedAttackDamage), _armorDamageReduction(armorDamageReduction)
{
    std::cout << "Initializing ClapTrap....." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap shutting down....." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & other) : _maxHitPoints(other._maxHitPoints), _maxEnergyPoints(other._maxEnergyPoints) 
{
    std::cout << "Initializing ClapTrap....." << std::endl;

    *this = other;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & other)
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

void ClapTrap::rangedAttack(std::string const & target)
{
    std::cout << this->_model << " <" << this->_name << ">";
    std::cout << " attacks " << target;
    std::cout << " at range, causing " << this->_rangedAttackDamage;
    std::cout << " points of damage !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
    std::cout << this->_model << " <" << this->_name << ">";
    std::cout << " attacks " << target;
    std::cout << " up close, causing " << this->_meleeAttackDamage;
    std::cout << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    int checkAmount = amount;
    if (checkAmount < 0)
        amount = 0;
    int damage = amount - this->_armorDamageReduction;
    if (damage < 0)
        damage = 0;
    int newHP = this->_hitPoints - damage;

    std::cout << this->_model << " <" << this->_name << ">";
    std::cout << " takes " << amount << " points of damage";
    std::cout << " reduced by " << this->_armorDamageReduction << " for a total of ";
    std::cout << damage << " points!" << std::endl;

    if (newHP >= 0)
         this->_hitPoints = newHP;
    else
        this->_hitPoints = 0;
    
    std::cout << "Total hp is now: " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    int checkAmount = amount;
    if (checkAmount < 0)
        amount = 0;

    std::cout << this->_model << " <" << this->_name << ">";
    std::cout << " is repaired for ";
    std::cout << amount << " hitpoints!" << std::endl;

    int newHP = this->_hitPoints + amount;
    if (newHP <= this->_maxHitPoints)
        this->_hitPoints = newHP;
    else
        this->_hitPoints = this->_maxHitPoints;

    std::cout << "Total hp is now: " << this->_hitPoints << std::endl;
}