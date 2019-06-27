/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:28:23 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/09 15:28:25 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> nums;
    for (int i = 0; i < 100; i++)
        nums.push_back(i);
    
    for (int i = 90; i < 110; i++)
    {
        try{
            std::cout << easyfind(nums, i) << std::endl;
        } catch (std::exception& e)
        {
            std::cout << "Couldn't find " << i << std::endl;
        }
    }
    
    return 0;
}
