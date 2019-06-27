/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:43:54 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 20:21:03 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat *b = nullptr;
    Form *rf = nullptr;
    Form *sf = nullptr;
    Form *pf = nullptr;
    
    try
    {
        b = new Bureaucrat("Billy", 50);
    }
    catch (Bureaucrat::GradeTooLowException& gradeTooLow)
    {
        std::cout << gradeTooLow.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& gradeTooHigh)
    {
        std::cout << gradeTooHigh.what() << std::endl;
    }

    try
    {
        rf = new RobotomyRequestForm("garbage");
    }
    catch (Form::GradeTooLowException& gradeTooLow)
    {
        std::cout << gradeTooLow.what() << std::endl;
    }
    catch (Form::GradeTooHighException& gradeTooHigh)
    {
        std::cout << gradeTooHigh.what() << std::endl;
    }

    std::cout << "Shrubbery: " << std::endl;

    sf = new ShrubberyCreationForm(".");

    b->signForm(*sf);
    b->executeForm(*sf);

    std::cout << std::endl << std::endl;
    std::cout << "Robotomy: " << std::endl;

    b->executeForm(*rf);

    b->signForm(*rf);

    b->executeForm(*rf);

    std::cout << *b << std::endl;

    std::cout << *rf << std::endl;

    for (int i = 0; i < 6; i++)
    {
        b->incrementGrade();
    }

    std::cout << *b << std::endl;
    

    b->executeForm(*rf);

    std::cout << std::endl << std::endl;

    std::cout << "Presidential: " << std::endl;

    Bureaucrat *p = new Bureaucrat("President", 5);
    pf = new PresidentialPardonForm("Nobody");
    p->signForm(*pf);
     p->executeForm(*pf);
    
    if (b != nullptr)
        delete b;

    if (rf != nullptr)
        delete rf;

    if (pf != nullptr)
        delete pf;

    if (sf != nullptr)
        delete sf;

    if (p != nullptr)
        delete p;
    
    return 0;
}
