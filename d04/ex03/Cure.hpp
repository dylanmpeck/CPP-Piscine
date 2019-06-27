/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:28:16 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 12:28:39 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
    
private:
    Cure(int xp);
    
public:
    Cure();
    ~Cure();
    Cure(Cure const &);
    Cure const & operator=(Cure const &);
    
    AMateria *clone() const;
};

#endif
