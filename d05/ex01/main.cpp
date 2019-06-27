/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:43:54 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 17:30:08 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *b = nullptr;
    Form *f = nullptr;
    
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
        f = new Form("my form", 49, 1);
    }
    catch (Form::GradeTooLowException& gradeTooLow)
    {
        std::cout << gradeTooLow.what() << std::endl;
    }
    catch (Form::GradeTooHighException& gradeTooHigh)
    {
        std::cout << gradeTooHigh.what() << std::endl;
    }

    b->signForm(*f);
    
    b->incrementGrade();

    b->signForm(*f);

    std::cout << *f << std::endl;
    
    if (b != nullptr)
        delete b;

    if (f != nullptr)
        delete f;
    
    return 0;
}
