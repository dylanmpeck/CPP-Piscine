/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:46:16 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 19:27:43 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("DEFAULT", "", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string targetPath) : Form("Shrubbery Creation Form", targetPath, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm const & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    if (this != &rhs)
    {
        *this = ShrubberyCreationForm(this->getTarget());
        Form::operator=(rhs);
    }
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other) : 
                                                Form(other.getName(), other.getTarget(), other.getGradeRequiredToSign(), other.getGradeRequiredtoExecute())
{
    Form::operator=(other);
}

void ShrubberyCreationForm::beExecuted() const
{
    std::string targetFile = this->getTarget();
    targetFile += "/_shrubbery";
    std::ofstream outFile(targetFile);
    if (outFile.fail() || outFile.is_open() == false)
        std::cout << "Invalid target. Shrubbery not written to file." << std::endl;
    outFile << "                ,@@@@@@@,\n";
    outFile << "   ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    outFile << ",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    outFile << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    outFile << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    outFile << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    outFile << "`&%\\ ` /%&'    |.|        \\ '|8'\n";
    outFile << "    |o|        | |         | |\n";
    outFile << "    |.|        | |         | |\n";
    outFile << "\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
}