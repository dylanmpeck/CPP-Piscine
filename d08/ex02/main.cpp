/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:13:10 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/09 17:24:02 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top of stack: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size of stack: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::const_iterator it = mstack.begin();
    MutantStack<int>::const_iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << std::endl;
    std::cout << "Iterator: " << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;
    std::cout << "Check copy (should be reverse from iterator)" << std::endl;
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        std::cout << x << std::endl;
    }

    return 0;
}
