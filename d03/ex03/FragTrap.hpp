/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:25:32 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 20:17:27 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
            
public:
    FragTrap();
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(FragTrap const & other);
    FragTrap & operator=(FragTrap const & other);

    void vaulthunter_dot_exe(std::string const & target);
    void taunt(std::string const & target);
    void magicMissile(std::string const & target);
    void runAway(std::string const & target);
    void cardThrow(std::string const & target);
    void powerUp(std::string const & target);
};

#endif