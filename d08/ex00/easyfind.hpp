/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:28:04 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/09 15:28:18 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
int easyfind(T& container, int data)
{
    typename T::iterator it = std::find(container.begin(), container.end(), data);
    
    if (it == container.end())
        throw (std::exception());
    
    return (*it);
}

#endif
