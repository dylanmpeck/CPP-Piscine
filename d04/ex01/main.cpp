/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:46:56 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 17:41:04 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"
#include "AWeapon.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
    Character* zaz = new Character("zaz");
    std::cout << *zaz;
    Enemy* b = new RadScorpion();
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);
    zaz->attack(b);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;


	AWeapon* copy = new PlasmaRifle(*(dynamic_cast<PlasmaRifle *>(pr)));
	Enemy *c = new SuperMutant();
	zaz->equip(copy);
	zaz->attack(c);
	Enemy* eCopy = new SuperMutant(*(dynamic_cast<SuperMutant *>(c)));
	zaz->attack(c);
	std::cout << *zaz;
	
	delete eCopy;
	delete c;
	delete copy;
    delete pf;
    delete pr;
    delete zaz;
    return (0);
}
