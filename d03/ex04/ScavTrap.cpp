/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:55:51 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 21:25:11 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(100, 100, 50, 50, 1, "Noname", "SC4V-TP", 20, 15, 3)
{
    std::cout << this->_name << ": Watap. I am a scavtrap. Hear me roar!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(100, 100, 50, 50, 1, name, "SC4V-TP", 20, 15, 3)
{
    std::cout << this->_name << ": Watap. I am a scavtrap. Hear me roar!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->_name << ": OH NO THIS IS THE END" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & other)
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

void ScavTrap::challengeNewcomer(std::string const & target)
{
    std::string challenges[] = {"You fight like a Dairy Farmer",
                                "I've spoken with apes more polite than you",
                                "This is the END for you, you gutter crawling cur",
                                "There are no words for how disgusting you are",
                                "You have the manners of a beggar"};
    int challengeIdx = rand() % 5;
    std::cout << challenges[challengeIdx] << " " << target << "!" << std::endl;
}