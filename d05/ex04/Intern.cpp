/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:03:31 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 20:17:56 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern const & Intern::operator=(Intern const & rhs)
{
    (void)rhs;
    return (*this);
}

Intern::Intern(Intern const & other)
{
    *this = other;
}

Form * Intern::makeForm(std::string name, std::string target)
{
    for (size_t i = 0; i < name.length(); i++)
    {
        if (name[i] >= 'A' && name[i] <= 'Z')
            name[i] += 32;
    }

    Form *form = nullptr;

    if (name == "shrubbery creation")
        form = new ShrubberyCreationForm(target);
    else if (name == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (name == "presidential pardon")
        form = new PresidentialPardonForm(target);
    else
    {
        std::cout << "Error: Intern cannot find the " << name << " form!" << std::endl;
        return (nullptr);
    }
    return (form);
}