/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:23:10 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 21:29:11 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
    Human human;
    human.action("intimidatingShout", "Bob");
    human.action("meleeAttack", "Taxes");
    human.action("rangedAttack", "An apple");
    return (0);
}