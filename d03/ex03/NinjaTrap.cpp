/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:03:18 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 14:03:26 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap(60, 60, 120, 120, 1, "Noname", "Ninja-TP", 60, 5, 0)
{
    std::cout << this->_name << ": Ninjaaaaaaaa!" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(60, 60, 120, 120, 1, name, "Ninja-TP", 60, 5, 0)
{
    std::cout << this->_name << ": Ninjaaaaaaaaa!" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
    std::cout << this->_name << ": Peace." << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & other)
{
    std::cout << other._name << ": Ninjaaaaaaaaa!" << std::endl;
    
    *this = other;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & other)
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


void NinjaTrap::ninjaShoebox(ClapTrap & target)
{
    std::cout << "Ninja-TP <" << this->_name << "> tries to use ninja mind tricks on CL4P-TP " << target.getName() << ".... " << std::endl;
    int chance = rand() % 100;
    if (chance >= 60)
    {
        std::cout << "SUCCESS: " << target.getName() << " thinks it's a shoebox and powers down." << std::endl;
        target.setHitPoints(0);
        target.setEnergyPoints(0);
        std::cout << "CL4P-TP <" << target.getName() << "> HP is now " << target.getHitPoints();
        std::cout << "! Energy is now " << target.getEnergyPoints() << "!!" << std::endl;
    }
    else if (chance <= 20)
    {
        std::cout << "CRITICAL FAILURE: " << this->_name << " tripped on a rock and exploded!" << std::endl;
        this->_hitPoints = 0;
        std::cout << "Ninja-TP <" << this->_name << "> HP is now " << this->_hitPoints << " !" << std::endl;
    }
    else
        std::cout << "FAIL: CL4P-TP <" << target.getName() << "> is unfazed by the magicks." << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap & target)
{
    std::cout << "Ninja-TP <" << this->_name << "> tries to use ninja mind tricks on FR4G-TP " << target.getName() << ".... " << std::endl;
    int chance = rand() % 100;
    if (chance >= 80)
    {
        std::cout << "SUCCESS: " << target.getName() << " thinks it's a shoebox and powers down." << std::endl;
        target.setHitPoints(1);
        target.setEnergyPoints(1);
        std::cout << "FR4G-TP <" << target.getName() << "> HP is now " << target.getHitPoints();
        std::cout << "! Energy is now " << target.getEnergyPoints() << "!!" << std::endl;
    }
    else if (chance <= 30)
    {
        std::cout << "CRITICAL FAILURE: " << this->_name << " tripped on a rock and exploded!" << std::endl;
        this->_hitPoints = 1;
        std::cout << "Ninja-TP <" << this->_name << "> HP is now " << this->_hitPoints << " !" << std::endl;
    }
    else
        std::cout << "FAIL: FR4G-TP " << target.getName() << " is unfazed by the magicks." << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap & target)
{
    std::cout << "Ninja-TP <" << this->_name << "> tries to use ninja mind tricks on SC4V-TP " << target.getName() << ".... " << std::endl;
    int chance = rand() % 100;
    if (chance >= 50)
    {
        std::cout << "SUCCESS: " << target.getName() << " thinks it's a shoebox and powers down." << std::endl;
        target.setHitPoints(1);
        target.setEnergyPoints(1);
        std::cout << "SC4V-TP <" << target.getName() << "> HP is now " << target.getHitPoints();
        std::cout << "! Energy is now " << target.getEnergyPoints() << "!!" << std::endl;
    }
    else if (chance <= 10)
    {
        std::cout << "CRITICAL FAILURE: " << this->_name << " tripped on a rock and exploded!" << std::endl;
        this->_hitPoints = 1;
        std::cout << "Ninja-TP <" << this->_name << "> HP is now " << this->_hitPoints << " !" << std::endl;
    }
    else
        std::cout << "FAIL: SC4V-TP <" << target.getName() << "> is unfazed by the magicks." << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
    std::cout << "Ninja-TP <" << this->_name << "> tries to use ninja mind tricks on Ninja-TP " << target.getName() << "....." << std::endl;
    std::cout << "A mind battle begins!" << std::endl;
    int chance = rand() % 100;
    
    if (chance >= 80)
    {
        std::cout << this->_name << " wins! " << target.getName() << " explodes!" << std::endl;
        target.setHitPoints(1);
        std::cout << target.getName() << " HP is now " << target.getHitPoints() << "!!" << std::endl;
    }
    else if (chance <= 20)
    {
        std::cout << target.getName() << " wins! " << this->_name << " explodes!" << std::endl;
        this->_hitPoints = 1;
        std::cout << this->_name << " HP is now " << this->_hitPoints << "!!" << std::endl;
    }
    else
        std::cout << "No one really gets hurt. Nothing really happens." << std::endl;
}
