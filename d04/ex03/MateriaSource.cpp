/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:29:48 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 12:33:44 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materiaCount(0)
{
    for (int i = 0; i < 4; i++)
        this->_knownMateria[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_knownMateria[i] != NULL)
        {
            for (int j = 0; j < 4; j++)
            {
                if (this->_knownMateria[i] == this->_knownMateria[j]
                    && j != i)
                    this->_knownMateria[j] = NULL;
            }
            delete this->_knownMateria[i];
            this->_knownMateria[i] = NULL;
        }
    }
}

MateriaSource const & MateriaSource::operator=(const MateriaSource & rhs)
{
	if (this == &rhs)
		return (*this);

    for (int i = 0; i < 4; i++)
    {
        if (this->_knownMateria[i] != NULL)
        {
            for (int j = 0; j < 4; j++)
            {
                if (this->_knownMateria[i] == this->_knownMateria[j]
                    && j != i)
                    this->_knownMateria[j] = NULL;
            }
            delete this->_knownMateria[i];
            this->_knownMateria[i] = NULL;
        }
        if (rhs._knownMateria[i] != NULL)
            this->_knownMateria[i] = rhs._knownMateria[i]->clone();
    }
    
    this->_materiaCount = rhs._materiaCount;
    
    return (*this);
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    *this = other;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (m == NULL || this->_materiaCount >= 4)
        return;
    
    this->_knownMateria[this->_materiaCount] = m;
    this->_materiaCount++;
}

AMateria * MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_knownMateria[i] &&
            this->_knownMateria[i]->getType() == type)
            return (this->_knownMateria[i]->clone());
    }
    return (NULL);
}
