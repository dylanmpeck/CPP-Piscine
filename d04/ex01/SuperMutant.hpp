/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:19:02 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 17:37:55 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy {

public:
    SuperMutant();
    ~SuperMutant();
    SuperMutant(SuperMutant const &);
    SuperMutant & operator=(SuperMutant const &);

    void takeDamage(int damage);
};

#endif