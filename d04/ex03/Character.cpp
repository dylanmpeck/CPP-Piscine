/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:27:28 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:44:18 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("DEFAULT NAME")
{
    for (int i = 0; i < 4; i++)
        this->_equippedMateria[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_equippedMateria[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_equippedMateria[i] != NULL)
        {
            for (int j = 0; j < 4; j++)
            {
                if (this->_equippedMateria[i] == this->_equippedMateria[j]
                    && j != i)
                    this->_equippedMateria[j] = NULL;
            }
            delete this->_equippedMateria[i];
            this->_equippedMateria[i] = NULL;
        }
    }
}

Character const & Character::operator=(const Character & rhs)
{
	if (this == &rhs)
		return (*this);

    for (int i = 0; i < 4; i++)
    {
        if (this->_equippedMateria[i] != NULL)
        {
            for (int j = 0; j < 4; j++)
            {
                if (this->_equippedMateria[i] == this->_equippedMateria[j]
                    && j != i)
                    this->_equippedMateria[j] = NULL;
            }
            delete this->_equippedMateria[i];
            this->_equippedMateria[i] = NULL;
        }
        if (rhs._equippedMateria[i] != NULL)
            this->_equippedMateria[i] = rhs._equippedMateria[i]->clone();
    }
    
    this->_name = rhs._name;
    
    return (*this);
}

ICharacter const & Character::operator=(const ICharacter & rhs)
{
    const Character *pC = dynamic_cast<const Character*>(&rhs);
    
    if (pC)
    {
		if (this == pC)
			return (*this);

        for (int i = 0; i < 4; i++)
        {
            if (this->_equippedMateria[i] != NULL)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (this->_equippedMateria[i] == this->_equippedMateria[j]
                        && j != i)
                        this->_equippedMateria[j] = NULL;
                }
                delete this->_equippedMateria[i];
                this->_equippedMateria[i] = NULL;
            }
            if (pC->_equippedMateria[i] != NULL)
                this->_equippedMateria[i] = pC->_equippedMateria[i]->clone();
        }
        
        this->_name = pC->_name;
    }
    
    return (*this);
}


Character::Character(Character const & other) : ICharacter()
{
    *this = other;
}

Character::Character(ICharacter const & other) : ICharacter()
{
    *this = other;
}

std::string const & Character::getName() const { return this->_name; }

void Character::equip(AMateria * m)
{
    if (m == NULL)
        return;
    
    int i = 0;
    while (i < 4 && this->_equippedMateria[i])
        i++;
    if (i < 4)
        this->_equippedMateria[i] = m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        this->_equippedMateria[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->_equippedMateria[idx] != NULL)
        this->_equippedMateria[idx]->use(target);
}
