/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:26:51 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 12:32:07 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _xp(0), _type("") {}

AMateria::AMateria(std::string const & type) : _xp(0), _type(type) {}

AMateria::~AMateria() {}

AMateria const & AMateria::operator=(AMateria const & rhs)
{
	if (this == &rhs)
		return (*this);

    this->_xp = rhs._xp;
    this->_type = rhs._type;
    
    return (*this);
}

AMateria::AMateria(AMateria const & other)
{
    *this = other;
}

std::string const & AMateria::getType() const { return this->_type; }

void AMateria::setType(std::string const & type) { this->_type = type; }

void AMateria::setXP(unsigned int xp) { this->_xp = xp; }

unsigned int AMateria::getXP() const { return this->_xp; }

void AMateria::use(ICharacter &target)
{
    if (this->_type == "ice")
        std::cout << "* shoots an ice at " << target.getName() << " *" << std::endl;
    else if (this->_type == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    else
        std::cout << "* uses the " << this->_type << " materia on " << target.getName() << " *" << std::endl;
    
    this->_xp += 10;
}
