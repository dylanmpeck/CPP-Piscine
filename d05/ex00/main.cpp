/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:43:54 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 16:43:59 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *b = nullptr;
    
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
    
    if (b != nullptr)
        std::cout << *b << std::endl;
    
    for (int i = 0; i < 120; i++)
    {
        try {
            b->decrementGrade();
        } catch (Bureaucrat::GradeTooHighException& gradeTooHigh) {
            std::cout << gradeTooHigh.what() << std::endl;
        } catch (Bureaucrat::GradeTooLowException& gradeTooLow) {
            std::cout << gradeTooLow.what() << std::endl;
        }
        std::cout << *b << std::endl;
    }
    
    if (b != nullptr)
        delete b;
    return 0;
}
