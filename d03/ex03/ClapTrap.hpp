/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:42:29 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 21:25:13 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

protected:
    int _hitPoints;
    int const _maxHitPoints;
    int _energyPoints;
    int const _maxEnergyPoints;
    int _level;
    std::string _name;
    std::string _model;
    int _meleeAttackDamage;
    int _rangedAttackDamage;
    int _armorDamageReduction;

    ClapTrap(int hitPoints, int const maxHitPoints, int energyPoints, int const maxEnergyPoints, 
            int level, std::string name, std::string model, int meleeAttackDamage,
            int rangedAttackDamage, int armorDamageReduction);

public:
    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap(ClapTrap const & other);
    ClapTrap & operator=(ClapTrap const & other);
    

    void rangedAttack(std::string const & target);
    void meleeAttack(std::string const & target);
    void beRepaired(unsigned int amount);
    void takeDamage(unsigned int amount);
    
    std::string getName();
    void setHitPoints(int hp);
    void setEnergyPoints(int energy);
    int getHitPoints();
    int getEnergyPoints();
};

#endif
