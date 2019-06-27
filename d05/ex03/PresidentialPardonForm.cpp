/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:25:04 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 19:15:32 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("DEFAULT", "", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm const & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    if (this != &rhs)
    {
        *this = PresidentialPardonForm(this->getTarget());
        Form::operator=(rhs);
    }
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other) : 
                                                Form(other.getName(), other.getTarget(), other.getGradeRequiredToSign(), other.getGradeRequiredtoExecute())
{
    Form::operator=(other);
}

void PresidentialPardonForm::beExecuted() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}