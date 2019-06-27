/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:29:31 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 15:52:04 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent {

private:
    std::string _type;  
    std::string nameGen();

public:
    ZombieEvent();
    ~ZombieEvent();

    void setZombieType(std::string type);
    Zombie* newZombie(std::string name);
    void randomChump();
};

#endif