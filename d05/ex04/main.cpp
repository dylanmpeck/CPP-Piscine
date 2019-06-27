/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:43:54 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/07 13:26:15 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "OfficeBlock.hpp"

int main()
{
    Intern myIntern;
    Bureaucrat *signB = new Bureaucrat("Sign guy", 50);
    Bureaucrat *execB = new Bureaucrat("Exec guy", 37);
    OfficeBlock ob;
    
    ob.setIntern(&myIntern);
    ob.setSigner(signB);
    ob.setExecutor(execB);

    try
    {
        ob.doBureaucracy("presidential pardon", "Nobody");
    }
    catch(OfficeBlock::InvalidFormException& invalidForm)
    {
        std::cout << "Bureaucracy wasn't done becaue " << invalidForm.what() << std::endl;
    }
    catch (OfficeBlock::BlockNotFullException& blockNotFull)
    {
        std::cout << "Bureaucracy wasn't done because " << blockNotFull.what() << std::endl;
    }
    
    
    return 0;
}
