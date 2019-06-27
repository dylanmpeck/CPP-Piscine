/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:50:13 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:46:29 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim() : _name("DEFAULT NAME")
{
    std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::Victim(std::string name) : _name(name)
{
    std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

Victim::Victim(Victim const & other)
{
    std::cout << "Some random victim called " << other._name << " just popped !" << std::endl;

   *this = other; 
}

Victim & Victim::operator=(Victim const & other)
{
	if (this == &other)
		return (*this);

    this->_name = other._name;

    return (*this);
}

std::string Victim::getName() const
{
    return (this->_name);
}

void Victim::introduce()
{
    std::cout << "I'm " << this->_name << " and I like otters !" << std::endl;
}

void Victim::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Victim const & rhs)
{
    o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
    return (o);
}   
