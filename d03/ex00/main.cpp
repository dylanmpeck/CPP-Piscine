/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:01:22 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 17:45:48 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    srand(time(0));
    FragTrap ft("Clap");
    ft.meleeAttack("bad guy");
    ft.rangedAttack("bad guy");
    ft.takeDamage(50);
    ft.takeDamage(70);
    ft.beRepaired(30);
    ft.beRepaired(150);
    ft.vaulthunter_dot_exe("George Washington");
    ft.vaulthunter_dot_exe("Abraham Lincoln");
    ft.vaulthunter_dot_exe("Garbage");
    ft.vaulthunter_dot_exe("Darkness");
    ft.vaulthunter_dot_exe("should fail");
    return (0);
}