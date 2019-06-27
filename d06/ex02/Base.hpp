/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:56:03 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 13:56:15 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
  
public:
    Base();
    virtual ~Base();
    Base(Base const &);
    Base const & operator=(Base const &);
    
};

#endif
