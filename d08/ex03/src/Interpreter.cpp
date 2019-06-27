/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:34:16 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 16:38:16 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interpreter.hpp"
#include "IncrementPointer.hpp"
#include "IncrementByteAtPointer.hpp"
#include "DecrementPointer.hpp"
#include "DecrementByteAtPointer.hpp"
#include "Output.hpp"
#include "Input.hpp"
#include "OpenBrackets.hpp"
#include "ClosedBrackets.hpp"

Interpreter::Interpreter()
{
}

Interpreter::~Interpreter()
{
    for (unsigned long i = 0; i < this->_instructions.size(); i++)
        delete this->_instructions[i];
}

Interpreter::Interpreter(Interpreter const & other) 
{
    *this = other;
}

Interpreter const & Interpreter::operator=(Interpreter const & rhs)
{
    if (this != &rhs)
    {
        this->_container = rhs._container;
        this->_instructions = rhs._instructions;
        this->_ss << rhs._ss.rdbuf();
    }
    return (*this);
}

void Interpreter::interpret(char *fileName)
{
    std::ifstream file(fileName);

    if (file)
    {
        this->_ss << file.rdbuf();
        file.close();
    }
    else
        throw(std::exception());
    
    parseInstructions();
    executeInstructions();
}

void Interpreter::parseInstructions()
{
    std::string fileData = _ss.str();
    std::string::iterator it = fileData.begin();
    while (it != fileData.end())
    {
        Instruction *i = nullptr;

        switch(*it)
        {
            case '>':
                i = new IncrementPointer();
                break;
            case '<':
                i = new DecrementPointer();
                break;
            case '+':
                i = new IncrementByteAtPointer();
                break;
            case '-':
                i = new DecrementByteAtPointer();
                break;
            case '.':
                i = new Output();
                break;
            case ',':
                i = new Input();
                break;
            case '[':
                i = new OpenBrackets();
                break;
            case ']':
                i = new ClosedBrackets();
                break;
        }

        it++;
        
        if (i == NULL)
            continue;

        this->_instructions.push_back(i);
    }
}

void Interpreter::executeInstructions()
{
    for (unsigned long i = 0; i < this->_instructions.size(); i++)
    {
        if (OpenBrackets *ob = dynamic_cast<OpenBrackets *>(this->_instructions[i]))
            this->openBrackets(i);
        else if (ClosedBrackets *cb = dynamic_cast<ClosedBrackets *>(this->_instructions[i]))
            this->closedBrackets(i);
        else
            this->_instructions[i]->execute(this->_container);
    }
}

void Interpreter::openBrackets(unsigned long & idx)
{
    int bal = 1;
    if (*(this->_container.getDataAtCurPos()) == '\0')
    {
        do {
            idx++;
            if (OpenBrackets *ob = dynamic_cast<OpenBrackets *>(this->_instructions[idx]))
                bal++;
            else if (ClosedBrackets *cb = dynamic_cast<ClosedBrackets *>(this->_instructions[idx]))
                bal--;
        }
        while (bal != 0);
    }
}

void Interpreter::closedBrackets(unsigned long & idx)
{
    int bal = 0;
    if (*(this->_container.getDataAtCurPos()) != '\0')
    {
        do {
            if (OpenBrackets *ob = dynamic_cast<OpenBrackets *>(this->_instructions[idx]))
                bal++;
            else if (ClosedBrackets *cb = dynamic_cast<ClosedBrackets *>(this->_instructions[idx]))
                bal--;
            idx--;
        }
        while (bal != 0);
    }
}