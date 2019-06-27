/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:48:08 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 18:11:59 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    unsigned int size = 30;
    Array<int> array1(size);
    Array<int> array2;
    array1[10] = 10;
    array1[20] = 20;
    std::cout << "Array1: " << array1[10] << " " << array1[20] << std::endl;
    array2 = array1;
    array1[10] = 0;
    array1[20] = 0;
    std::cout << "Array2: " << array2[10] << " " << array2[20] << std::endl;

    try {
        array1[500] = 2;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Still running." << std::endl;

    return (0);
}