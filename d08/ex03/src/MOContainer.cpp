/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MOContainer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:59:16 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 16:13:32 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MOContainer.hpp"

int const MOContainer::_size = 30000;

MOContainer::MOContainer()
{
    this->_data = new char [this->_size];
    std::fill(_data, _data + _size, 0);
    this->_position = 0;    
}

MOContainer::~MOContainer()
{
    if (this->_data)
        delete [] this->_data;
}

MOContainer const & MOContainer::operator=(MOContainer const & rhs)
{
    if (this != &rhs)
    {
        if (_data)
            delete [] _data;
        
        this->_data = new char [rhs._size];

        for (int i = 0; i < rhs._size; i++)
        {
            if (rhs._data[i] != '\0')
                this->_data[i] = rhs._data[i];
        }

        this->_position = rhs._position;
    }
    return (*this);
}

MOContainer::MOContainer(MOContainer const & other)
{
    *this = other;
}

void MOContainer::setPosition(int pos)
{
    this->_position = pos;
}

int MOContainer::getPosition()
{
    return (this->_position);
}

char * MOContainer::getDataAtCurPos()
{
    return (this->_data + this->_position);    
}