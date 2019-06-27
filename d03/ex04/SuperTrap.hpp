/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:54:43 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 13:58:52 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SuperTrap_hpp
#define SuperTrap_hpp

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
    
public:
    SuperTrap();
    SuperTrap(std::string name);
    ~SuperTrap();
    SuperTrap(SuperTrap const & other);
    SuperTrap & operator=(SuperTrap const & other);
    
    void meleeAttack(std::string const & target);
    void rangedAttack(std::string const & target);
};

#endif
