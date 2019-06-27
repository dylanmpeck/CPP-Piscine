/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:07:55 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 15:51:45 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "Instruction.hpp"
#include "MOContainer.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Interpreter {

private:
    MOContainer _container;
    std::vector<Instruction *> _instructions;
    std::stringstream _ss;

public:
    Interpreter();
    ~Interpreter();
    Interpreter(Interpreter const &);
    Interpreter const & operator=(Interpreter const &);

    void openBrackets(unsigned long & idx);
    void closedBrackets(unsigned long & idx);

    void interpret(char *fileName);
    void parseInstructions();
    void executeInstructions();
};

#endif