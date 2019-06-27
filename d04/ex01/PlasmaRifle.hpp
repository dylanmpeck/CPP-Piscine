/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:42:22 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:42:02 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:
    PlasmaRifle();
    ~PlasmaRifle();
    PlasmaRifle(PlasmaRifle const &);
	PlasmaRifle(AWeapon const &);
    PlasmaRifle & operator=(PlasmaRifle const &);

    void attack() const;
};

#endif
