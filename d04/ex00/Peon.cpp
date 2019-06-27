/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:01:57 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:45:18 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon()
{
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(Peon const & other) : Victim(other)
{
    std::cout << "Zog zog." << std::endl;

   *this = other; 
}

Peon & Peon::operator=(Peon const & other)
{
	if (this == &other)
		return (*this);

    Victim::operator=(other);

    return *this;
}

void Peon::getPolymorphed() const
{
    std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}
