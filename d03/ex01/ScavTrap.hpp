/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:56:04 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 21:33:25 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>

class ScavTrap {
    
private:
    int _hitPoints;
    int const _maxHitPoints;
    int _energyPoints;
    int const _maxEnergyPoints;
    int _level;
    std::string _name;
    int _meleeAttackDamage;
    int _rangedAttackDamage;
    int _armorDamageReduction;

public:
    ScavTrap();
    ScavTrap(std::string name);
    ~ScavTrap();
    ScavTrap(ScavTrap const & other);
    ScavTrap & operator=(ScavTrap const & other);

    void challengeNewcomer(std::string const & target);
    void rangedAttack(std::string const & target);
    void meleeAttack(std::string const & target);
    void beRepaired(unsigned int amount);
    void takeDamage(unsigned int amount);
};

#endif