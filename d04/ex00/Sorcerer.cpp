/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:27:50 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:46:38 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer() : _name("DEFAULT NAME"), _title("DEFAULT TITLE")
{
    std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title << ", is dead.";
    std::cout << " Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & other)
{
   std::cout << other._name << ", " << other._title << ", is born !" << std::endl;

   *this = other; 
}

Sorcerer & Sorcerer::operator=(Sorcerer const & other)
{
	if (this == &other)
		return (*this);

    this->_name = other._name;
    this->_title = other._title;

    return (*this);
}

std::string Sorcerer::getName() const
{
    return (this->_name);
}

std::string Sorcerer::getTitle() const
{
    return (this->_title);
}

void Sorcerer::introduce()
{
    std::cout << "I am " << this->_name << ", " << this->_title << ", and I like ponies !" << std::endl;
}

void Sorcerer::polymorph(Victim const & victim) const
{
    victim.getPolymorphed();
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs)
{
    o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
    return (o);
}
