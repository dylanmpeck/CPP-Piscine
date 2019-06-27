/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:28:34 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/09 15:48:03 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"

int main() 
{
	Span span(10002);
	std::vector<int> large;
	for (int i = 0; i < 10000; i++)
		large.push_back(i);
	span.addByRange(large);
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << "Test negative and limits: " << std::endl;
	span.addNumber(INT_MIN);
	span.addNumber(INT_MAX);
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
    return 0;
}
