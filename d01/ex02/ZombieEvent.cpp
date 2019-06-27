/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:42:25 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 15:48:40 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() : _type("regular") {}

ZombieEvent::~ZombieEvent() {}

void ZombieEvent::setZombieType(std::string type)
{
    this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
    Zombie *zombie = new Zombie(name, this->_type);
    return (zombie);
}

std::string ZombieEvent::nameGen()
{
    std::string names[] = {"Refugio",
                            "Whitney",
                            "Abel",
                            "Erwin",
                            "Craig",
                            "Gerald",
                            "Zack",
                            "Wendell",
                            "Dwight",
                            "Gaston"};
    int idx = rand() % 10;
    return (names[idx]);
}

void ZombieEvent::randomChump()
{
    Zombie chump(nameGen(), this->_type);
    chump.announce();
}