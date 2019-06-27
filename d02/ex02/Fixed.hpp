/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:58:11 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 14:03:34 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:
    int _fixedPointValue;
    int static const _fractionalBitNumber;

public:
    Fixed();
    Fixed & operator=(Fixed const & other);
    ~Fixed();
    Fixed(Fixed const & rhs);

    Fixed(int const integerValue);
    Fixed(float const floatValue);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    bool operator==(Fixed const & other);
    bool operator!=(Fixed const & other);
    bool operator<(Fixed const & other);
    bool operator>(Fixed const & other);
    bool operator>=(Fixed const & other);
    bool operator<=(Fixed const & other);

    Fixed operator+(Fixed const & rhs);
    Fixed operator-(Fixed const & rhs);
    Fixed operator*(Fixed const & rhs);
    Fixed operator/(Fixed const & rhs);

    Fixed operator++();
    Fixed operator++(int);
    Fixed operator--();
    Fixed operator--(int);

    static Fixed & min(Fixed & lhs, Fixed & rhs);
    static Fixed const & min(Fixed const & lhs, Fixed const & rhs);
    static Fixed & max(Fixed & lhs, Fixed & rhs);
    static Fixed const & max(Fixed const & lhs, Fixed const & rhs);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
