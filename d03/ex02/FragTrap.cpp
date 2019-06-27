/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:32:11 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 21:24:20 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(100, 100, 100, 100, 1, "Noname", "FR4G-TP", 30, 20, 5)
{
    std::cout << this->_name << ": Directive one: Protect humanity! ";
    std::cout << "Directive two: Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(100, 100, 100, 100, 1, name, "FR4G-TP", 30, 20, 5)
{
    std::cout << this->_name << ": Directive one: Protect humanity! ";
    std::cout << "Directive two: Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << this->_name << ": I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

FragTrap::FragTrap(FragTrap const & other) 
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