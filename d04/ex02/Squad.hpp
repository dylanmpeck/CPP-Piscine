/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:10:10 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 22:30:24 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

typedef struct units
{
    ISpaceMarine *marine;
    struct units *next;
    units(ISpaceMarine * marine) : marine(marine), next(NULL) {};
}               Units;

class Squad : public ISquad {

private:
    int _count;
    Units *_units;

public:
    Squad();
    ~Squad();
    Squad(Squad const &);
    Squad & operator=(Squad const &);
    Squad & operator=(ISquad const &);

    int getCount() const;
    ISpaceMarine* getUnit(int) const;
    int push(ISpaceMarine *);

    void deleteUnits();
};

#endif