/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:26:46 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:43:38 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() : _count(0), _units(NULL) {}

Squad::~Squad()
{
    this->deleteUnits();
}

Squad & Squad::operator=(Squad const & rhs)
{
	if (this == &rhs)
		return (*this);

    this->deleteUnits();

    this->_count = 0;

    for (int i = 0; i < rhs.getCount(); i++)
        push(rhs.getUnit(i)->clone());

    return (*this);
}

Squad & Squad::operator=(ISquad const & rhs)
{
	if (this == &rhs)
		return (*this);

    this->deleteUnits();

    this->_count = 0;

    for (int i = 0; i < rhs.getCount(); i++)
        push(rhs.getUnit(i)->clone());

    return (*this);
}

Squad::Squad(Squad const & other)
{
    *this = other;
}

int Squad::push(ISpaceMarine *marine)
{
    if (marine == NULL)
        return(this->getCount());

    if (this->_units == NULL)
    {
        this->_units = new Units(marine);
        this->_count++;
        return (this->_count);
    }

    Units *trav = this->_units->next;
    Units *prev = this->_units;

    while (trav)
    {
        if (trav->marine == marine || prev->marine == marine)
            return (this->_count);
        prev = trav;
        trav = trav->next;
    }

    trav = new Units(marine);
    prev->next = trav;
    this->_count++;
    return (this->_count);
}

ISpaceMarine * Squad::getUnit(int unitIndex) const
{
    Units *trav = this->_units;
    int count = 0;

    while (trav)
    {
        if (count == unitIndex)
            return (trav->marine);

        trav = trav->next;
        count++;
    }

    return (NULL);
}

int Squad::getCount() const
{
    return (this->_count);
}

void Squad::deleteUnits()
{
    Units *trav = this->_units;
    Units *del;
    int i = 0;

    while (i < this->_count)
    {
        del = trav;
        trav = trav->next;
        delete del->marine;
        del->next = NULL;
        delete del;
        i++;
    }
    if (this->_units != NULL)
        this->_units = NULL;
}
