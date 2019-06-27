/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:05:28 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:42:25 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:
    PowerFist();
    ~PowerFist();
    PowerFist(PowerFist const &);
	PowerFist(AWeapon const &);
    PowerFist & operator=(PowerFist const &);

    void attack() const;
};

#endif
