/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:39:46 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 16:41:19 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < typename T, typename F >
void iter(T * arrayAddr, size_t arrayLen, F fn)
{
    for (size_t i = 0; i < arrayLen; i++)
    {
        fn(arrayAddr[i]);
    }
}

template < typename T >
void addOne(T &byte)
{
    byte += 1;
}

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    iter<int>(array, 10, addOne<int>);
    for (int i = 0; i < 10; i++)
        std::cout << array[i] << std::endl;

    std::cout << std::endl;
    std::string str = "abcdefghijklmnopqrstuvwxy";
    ::iter<char>(&str[0], 25, addOne<char>);
    std::cout << str << std::endl;

    std::cout << std::endl;
    float fArray[] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5};
    ::iter<float>(fArray, 10, addOne<float>);
    for (int i = 0; i < 10; i++)
        std::cout << fArray[i] << std::endl;

    return (0);
}