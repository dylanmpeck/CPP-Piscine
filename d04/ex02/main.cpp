/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:28:17 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:43:52 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{
	int				i;
	int				count;
	ISpaceMarine	*cur;

	ISpaceMarine	*bob = new TacticalMarine;
	ISpaceMarine	*jim = new AssaultTerminator;
	ISquad			*vlc = new Squad;
	ISquad			*cvl = new Squad;
	Squad			lcv;
	ISquad			*clv;

	vlc->push(bob);
	vlc->push(jim);

	i = 0;
	count = vlc->getCount();
	while (i < count)
	{
		cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		i++;
	}
	*cvl = *vlc;
	std::cout << "VLC main: " << vlc->getCount() << std::endl;
	std::cout << "CVL main: " << cvl->getCount() << std::endl;
    cur = cvl->getUnit(1);
    cur->battleCry();
	clv = new Squad(lcv);
    ISpaceMarine *robert = new TacticalMarine;
    clv->push(robert);
    std::cout << "main: " << vlc->getCount() << std::endl;
    *vlc = *clv;
	delete vlc;
	return (0);
}
