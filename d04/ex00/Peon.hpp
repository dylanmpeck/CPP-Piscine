/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:58:05 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 16:15:09 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim {

private:
    Peon();

public:
    Peon(std::string name);
    ~Peon();
    Peon(Peon const &);
    Peon & operator=(Peon const & other);

    void getPolymorphed() const;
};

#endif