/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:03:30 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 14:03:32 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {
  
public:
    NinjaTrap();
    NinjaTrap(std::string name);
    ~NinjaTrap();
    NinjaTrap(NinjaTrap const & other);
    NinjaTrap & operator=(NinjaTrap const & other);
    
    void ninjaShoebox(ClapTrap &);
    void ninjaShoebox(FragTrap &);
    void ninjaShoebox(ScavTrap &);
    void ninjaShoebox(NinjaTrap &);
};

#endif
