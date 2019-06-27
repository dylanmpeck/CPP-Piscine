/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:25:32 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 19:21:24 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>

class FragTrap {
            
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
    FragTrap();
    FragTrap(std::string name);

    ~FragTrap();
    FragTrap(FragTrap const & other);
    FragTrap & operator=(FragTrap const & other);

    virtual void rangedAttack(std::string const & target);
    virtual void meleeAttack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void vaulthunter_dot_exe(std::string const & target);
    void taunt(std::string const & target);
    void magicMissile(std::string const & target);
    void runAway(std::string const & target);
    void cardThrow(std::string const & target);
    void powerUp(std::string const & target);
};

#endif