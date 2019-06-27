/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:45:58 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 17:29:41 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "ZombieHorde.hpp"

int main()
{
    srand(time(0));
    ZombieEvent zEvent;
    Zombie *zombieptr = zEvent.newZombie("Bobby");
    zombieptr->announce();
    delete zombieptr;
    zEvent.setZombieType("headless");
    zombieptr = zEvent.newZombie("Harry");
    zombieptr->announce();
    delete zombieptr;
    zEvent.setZombieType("walker");
    zEvent.randomChump();
    zEvent.randomChump();
    std::cout << std::endl << std::endl;
    ZombieHorde horde(24);
    horde.announce();
    return (0);
}
