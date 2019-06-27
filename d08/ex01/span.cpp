/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:28:41 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/09 15:49:46 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : _N(n)
{
    this->_numbers.reserve(n);
}

Span::~Span() {}

Span const & Span::operator=(Span const & rhs)
{
    if (this != &rhs)
    {
        this->_N = rhs._N;
        this->_numbers = rhs._numbers;
    }
    return (*this);
}

Span::Span(Span const & other)
{
    *this = other;
}

void Span::addNumber(int num)
{
    if (_numbers.size() == _N)
        throw (std::exception());
    
    _numbers.push_back(num);
}

void Span::addByRange(std::vector<int> & vec)
{
    if (vec.size() + this->_numbers.size() > _N)
        throw (std::exception());
    
    _numbers.insert(_numbers.end(), vec.begin(), vec.end());
}

long Span::shortestSpan()
{
    if (_numbers.size() <= 1)
        throw (std::exception());
    
    std::vector<int> copy = this->_numbers;
    std::sort(copy.begin(), copy.end());
    
    long shortestSpan = INT_MAX;
	long dif;
    
    for (int i = 1; i < copy.size(); i++)
    {
		dif = std::abs(static_cast<long>(copy[i]) - static_cast<long>(copy[i - 1]));
        if (dif < shortestSpan)
            shortestSpan = copy[i] - copy[i - 1];
    }
    
    return (shortestSpan);
}

long Span::longestSpan()
{
    if (_numbers.size() <= 1)
        throw (std::exception());
    
    return (std::abs(static_cast<long>(*(std::max_element(_numbers.begin(), _numbers.end()))) -
            		static_cast<long>(*(std::min_element(_numbers.begin(), _numbers.end())))));
}
