/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:28:48 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/09 15:43:37 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <cstdlib>

class Span {
    
private:
    Span();
    unsigned int _N;
    std::vector<int> _numbers;
    
public:
    Span(unsigned int n);
    ~Span();
    Span(Span const &);
    Span const & operator=(Span const &);
    
    void addNumber(int num);
    void addByRange(std::vector<int> &);
    long shortestSpan();
    long longestSpan();
};

#endif
