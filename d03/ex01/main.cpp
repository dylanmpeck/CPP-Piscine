/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:01:22 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/02 19:32:04 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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

    std::cout << std::endl << std::endl;

    ScavTrap st("Scavmaster");
    st.meleeAttack("Theodore Roosevelt");
    st.rangedAttack("Andrew Jackson");
    st.takeDamage(50);
    st.takeDamage(70);
    st.beRepaired(30);
    st.beRepaired(150);
    st.challengeNewcomer("Toby");
    st.challengeNewcomer("Alexander Hamilton");
    st.challengeNewcomer("Bob");
    return (0);
}