/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:18:39 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 21:36:13 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

const int Human::actionNumber = 3;

void    Human::meleeAttack(std::string const & target)
{
    std::cout << "Melee attack on " << target << "!" << std::endl;
}

void    Human::rangedAttack(std::string const & target)
{
    std::cout << "Ranged attack on " << target << "!" << std::endl;
}

void    Human::intimidatingShout(std::string const & target)
{
    std::cout << "Intimidating shout on " << target << "!!" << std::endl;
}

void    Human::action(std::string const & action_name, std::string const & target)
{
    std::string actionNames[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

    typedef void (Human::*Actions)(std::string const & target);
    Actions actions[Human::actionNumber] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

    for (int i = 0; i < Human::actionNumber; i++)
    {
        if (actionNames[i] == action_name)
        {
            (this->*(actions[i]))(target);
            break;
        }
    }
}

