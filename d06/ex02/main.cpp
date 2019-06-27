/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:52:05 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 13:52:08 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    Base *b;
    
    int randIdx = rand() % 3;
    if (randIdx == 0)
        b = new A;
    else if (randIdx == 1)
        b = new B;
    else
        b = new C;
    return (b);
}

void identify_from_pointer(Base *p)
{
    std::cout << "From pointer: ";
    if (A *a = dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (B *b = dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (C *c = dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "undefined" << std::endl;
}

void identify_from_reference(Base &p)
{
    std::cout << "From reference: ";
    try {
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << "A" << std::endl;
    } catch (std::bad_cast& not_a)
    {
        try {
            static_cast<void>(dynamic_cast<B&>(p));
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast& not_b)
        {
            try {
                static_cast<void>(dynamic_cast<C&>(p));
                std::cout << "C" << std::endl;
            }
            catch (std::bad_cast& not_anything)
            {
                std::cout << not_anything.what() << ".type undefined" << std::endl;
            }
        }
    }
}

int main() 
{
    srand(time(0));
    Base *p = generate();
    identify_from_pointer(p);
    identify_from_reference(*p);
    delete p;
    return 0;
}
