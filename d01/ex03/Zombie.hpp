/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:20:35 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 16:16:53 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

private:
    std::string _name;
    std::string _type;

public:
    Zombie();
    Zombie(std::string name, std::string type);
    ~Zombie();

    void announce();
    void setName(std::string const name);
    void setType(std::string const type);
    std::string getName();
    std::string getType();
};

#endif