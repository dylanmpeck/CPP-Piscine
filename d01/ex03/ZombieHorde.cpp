/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:53:15 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 16:28:41 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : _numberOfZombies(N)
{
    if (N > 0)
    {
        this->_zombies = new Zombie[N];
        for (int i = 0; i < N; i++)
        {
            this->_zombies[i].setName(this->nameGen());
            this->_zombies[i].setType("horde");
        }
    }
    else
        std::cout << "Error: Bad alloc for horde. Needs positive number." << std::endl;
}

ZombieHorde::~ZombieHorde()
{
    std::cout << "Zombie horde deleted" << std::endl;
    if (this->_numberOfZombies > 0)
        delete [] this->_zombies;
}

void ZombieHorde::announce()
{
    for (int i = 0; i < this->_numberOfZombies; i++)
        this->_zombies[i].announce();
}

std::string ZombieHorde::nameGen()
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
                            "Gaston",
                            "Timothy",
                            "Pablo",
                            "Kim",
                            "Harrison",
                            "Gayle",
                            "Caleb",
                            "Sean",
                            "Arnulfo",
                            "Rosendo",
                            "Markus",
                            "Eddy",
                            "Noah",
                            "Sherwood",
                            "Neil"};
    int idx = rand() % 24;
    return (names[idx]);
}