/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:11:30 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 19:15:32 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("DEFAULT", "", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm const & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    if (this != &rhs)
    {
        *this = RobotomyRequestForm(this->getTarget());
        Form::operator=(rhs);
    }
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other) : 
                                                Form(other.getName(), other.getTarget(), other.getGradeRequiredToSign(), other.getGradeRequiredtoExecute())
{
    Form::operator=(other);
}

void RobotomyRequestForm::beExecuted() const
{
    std::cout << "* Drilling noises * " << std::endl;
    srand(time(0));
    int chance = rand() % 100;
    if (chance < 50)
        std::cout << "Success. " << this->getTarget() << " has been robotomized." << std::endl;
    else
        std::cout << "Failure. " << this->getTarget() << " was not robotomized." << std::endl;
}