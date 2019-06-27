/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:29:31 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 12:29:43 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    
private:
    Ice(int xp);
    
public:
    Ice();
    ~Ice();
    Ice(Ice const &);
    Ice const & operator=(Ice const &);
    
    AMateria *clone() const;
};

#endif
