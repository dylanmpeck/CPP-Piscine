/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:49:19 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 15:56:06 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {

private:
    std::string nameGen();
    Zombie *_zombies;
    int _numberOfZombies;

public:
    ZombieHorde(int N);
    ~ZombieHorde();

    void announce();
};

#endif