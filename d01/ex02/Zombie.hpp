/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:20:35 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 15:48:38 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

private:
    std::string const _name;
    std::string const _type;

public:
    Zombie();
    Zombie(std::string name, std::string type);
    ~Zombie();

    void announce();
    std::string const getName();
    std::string const getType();
};

#endif