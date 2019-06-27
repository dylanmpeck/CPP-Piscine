/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:02:40 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/01 19:32:47 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float const floatValue)
{
    std::cout << "Float constructor called" << std::endl;

    this->_fixedPointValue = (roundf(floatValue * (float)(1 << Fixed::_fractionalBitNumber)));
    return;
}

Fixed::Fixed(int const integerValue)
{
    std::cout << "Int constructor called" << std::endl;

    this->_fixedPointValue = integerValue << Fixed::_fractionalBitNumber;
    return;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const
{
    return ((float)this->_fixedPointValue / (float)(1 << Fixed::_fractionalBitNumber));
}

int Fixed::toInt() const
{
    return ((int)(this->_fixedPointValue / (1 << Fixed::_fractionalBitNumber)));
}

Fixed::Fixed(Fixed const & rhs)
{
    std::cout << "Copy constructor called" << std::endl;

    *this = rhs;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;

    this->_fixedPointValue = rhs.getRawBits();

    return *this;
}

int Fixed::getRawBits(void) const
{
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

int const Fixed::_fractionalBitNumber = 8;

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}