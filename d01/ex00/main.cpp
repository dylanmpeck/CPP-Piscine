/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:46:43 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 14:09:14 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheHeap()
{
    Pony *pony = new Pony("Roger", "Blue", "Brave");
    std::cout << "My name is " << pony->getName() << "." << std::endl;
    std::cout << "I am the pony on the heap." << std::endl;
    std::cout << "My mane is " << pony->getColor() << " and I am very " << pony->getTrait() << "." << std::endl;
    delete pony;
}

void ponyOnTheStack()
{
    Pony pony("Paul", "Purple", "Poor");
    std::cout << "My name is " << pony.getName() << "." << std::endl;
    std::cout << "I am the pony on the stack." << std::endl;
    std::cout << "My mane is " << pony.getColor() << " and I am very " << pony.getTrait() << "." << std::endl;
}

int main()
{
    ponyOnTheHeap();
    std::cout << std::endl;
    ponyOnTheStack();
    return (0);
}