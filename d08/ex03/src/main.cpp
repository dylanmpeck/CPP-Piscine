/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:40:50 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 14:43:30 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interpreter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);

    Interpreter interpreter;

    interpreter.interpret(argv[1]);

    return (0);
}