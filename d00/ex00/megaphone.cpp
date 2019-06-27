/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:52:49 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/29 14:14:48 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string cur_arg = argv[i];
			for (unsigned long i = 0; i < cur_arg.size(); i++)
				cur_arg[i] = std::toupper(cur_arg[i]);
			std::cout << cur_arg;
		}
		std::cout << std::endl;
	}
	return (0);
}
