/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:31:45 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 16:35:45 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string brainStr = "HI THIS IS BRAIN";
    std::string *brainPtr = &brainStr;
    std::string& brainRef = brainStr;
    
    std::cout << "Pointer: " << *brainPtr << std::endl;
    std::cout << "Reference: " << brainRef << std::endl;
    return (0);
}