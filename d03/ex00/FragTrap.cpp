/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:32:11 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 21:34:21 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : _hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100), 
                        _level(1), _name("Noname"), _meleeAttackDamage(30), _rangedAttackDamage(20),
                        _armorDamageReduction(5)
{
    std::cout << this->_name << ": Directive one: Protect humanity! ";
    std::cout << "Directive two: Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

FragTrap::FragTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100), 
                                        _level(1), _name(name), _meleeAttackDamage(30), _rangedAttackDamage(20),
                                        _armorDamageReduction(5)
{
    std::cout << this->_name << ": Directive one: Protect humanity! ";
    std::cout << "Directive two: Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << this->_name << ": I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

FragTrap::FragTrap(FragTrap const & other) : _maxHitPoints(other._maxHitPoints), _maxEnergyPoints(other._maxEnergyPoints) 
{
    std::cout << other._name << ": Directive one: Protect humanity! ";
    std::cout << "Directive two: Obey Jack at all costs. Directive three: Dance!" << std::endl;

    *this = other;
}

FragTrap & FragTrap::operator=(FragTrap const & other)
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

void FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << "<" << this->_name << ">";
    std::cout << " attacks " << target;
    std::cout << " at range, causing " << this->_rangedAttackDamage;
    std::cout << " points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << "<" << this->_name << ">";
    std::cout << " attacks " << target;
    std::cout << " up close, causing " << this->_meleeAttackDamage;
    std::cout << " points of damage !" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    int checkAmount = amount;
    if (checkAmount < 0)
        amount = 0;
    int damage = amount - this->_armorDamageReduction;
    if (damage < 0)
        damage = 0;
    int newHP = this->_hitPoints - damage;

    std::cout << "FR4G-TP " << "<" << this->_name << ">";
    std::cout << " takes " << amount << " points of damage";
    std::cout << " reduced by " << this->_armorDamageReduction << " for a total of ";
    std::cout << damage << " points!" << std::endl;

    if (newHP >= 0)
         this->_hitPoints = newHP;
    else
        this->_hitPoints = 0;
    
    std::cout << "Total hp is now: " << this->_hitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    int checkAmount = amount;
    if (checkAmount < 0)
        amount = 0;

    std::cout << "FR4G-TP " << "<" << this->_name << ">";
    std::cout << " is repaired for ";
    std::cout << amount << " hitpoints!" << std::endl;

    int newHP = this->_hitPoints + amount;
    if (newHP <= this->_maxHitPoints)
        this->_hitPoints = newHP;
    else
        this->_hitPoints = this->_maxHitPoints;

    std::cout << "Total hp is now: " << this->_hitPoints << std::endl;
}

void FragTrap::taunt(std::string const & target)
{
    std::cout << "FR4G-TP " << "<" << this->_name << ">"; 
    std::cout << " mocks " << target << ". ";
    std::cout << target << " feels ashamed." << std::endl;
}

void FragTrap::magicMissile(std::string const & target)
{
    std::cout << "FR4G-TP " << "<" << this->_name << ">"; 
    std::cout << " casts magic missile on " << target << std::endl;
}

void FragTrap::runAway(std::string const & target)
{
    std::cout << "FR4G-TP " << "<" << this->_name << ">";
    std::cout << " bravely runs away from " << target << std::endl;
}

void FragTrap::cardThrow(std::string const & target)
{
    std::cout << "FR4G-TP " << "<" << this->_name << ">"; 
    std::cout << " throws a card at " << target;
    std::cout << " for 1 point of damage !" << std::endl;
}

void FragTrap::powerUp(std::string const & target)
{
    std::cout << "FR4G-TP " << "<" << this->_name << ">";
    std::cout << " starts powering up. ";
    std::cout << target << " looks confused." << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
    std::string attackNames[] = {"taunt", "magicMissle", "runAway", "cardThrow", "kamehameha"};

    typedef void (FragTrap::*Attacks)(std::string const &);
    Attacks attacks[] = {&FragTrap::taunt, &FragTrap::magicMissile, &FragTrap::runAway, &FragTrap::cardThrow, &FragTrap::powerUp};
    int randAttackNum = rand() % 5;

    if (this->_energyPoints >= 25)
    {
        (this->*(attacks[randAttackNum]))(target);
        this->_energyPoints -= 25;
    }
    else
        std::cout << "Not enough energy to run vaulthunter_dot_exe." << std::endl;
    
}