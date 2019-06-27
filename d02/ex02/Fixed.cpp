/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:02:40 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/01 20:55:02 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(float const floatValue)
{

    this->_fixedPointValue = (roundf(floatValue * (float)(1 << Fixed::_fractionalBitNumber)));
    return;
}

Fixed::Fixed(int const integerValue)
{

    this->_fixedPointValue = integerValue << Fixed::_fractionalBitNumber;
    return;
}

Fixed::~Fixed() {}

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
    *this = rhs;
}

int Fixed::getRawBits(void) const
{
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

Fixed & Fixed::operator=(Fixed const & other)
{
    this->_fixedPointValue = other.getRawBits();

    return *this;
}

bool Fixed::operator!=(Fixed const & other)
{
    return (this->_fixedPointValue != other._fixedPointValue);
}

bool Fixed::operator==(Fixed const & other)
{
    return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator<(Fixed const & other)
{
    return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>(Fixed const & other)
{
    return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator>=(Fixed const & other)
{
    return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(Fixed const & other)
{
    return (this->_fixedPointValue <= other._fixedPointValue);
}

Fixed Fixed::operator+(Fixed const & rhs)
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + rhs._fixedPointValue);
    return (result);
}

Fixed Fixed::operator-(Fixed const & rhs)
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - rhs._fixedPointValue);
    return (result);
}

Fixed Fixed::operator*(Fixed const & rhs)
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue * rhs._fixedPointValue) >> Fixed::_fractionalBitNumber);
    return (result);
}

Fixed Fixed::operator/(Fixed const & rhs)
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue << 8) / rhs._fixedPointValue);
    return (result);
}

Fixed Fixed::operator++()
{
    this->_fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed const old(*this);
    ++(*this);
    return (old);
}

Fixed Fixed::operator--()
{
    this->_fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed const old(*this);
    --(*this);
    return (old);
}

Fixed & Fixed::min(Fixed & lhs, Fixed & rhs)
{
    if (lhs < rhs)
        return (lhs);
    return (rhs);
}

Fixed const & Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
    if (lhs._fixedPointValue < rhs._fixedPointValue)
        return (lhs);
    return (rhs);
}

Fixed & Fixed::max(Fixed & lhs, Fixed & rhs)
{
    if (lhs > rhs)
        return (lhs);
    return (rhs);
}

Fixed const & Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
    if (lhs._fixedPointValue > rhs._fixedPointValue)
        return (lhs);
    return (rhs);
}

int const Fixed::_fractionalBitNumber = 8;

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}