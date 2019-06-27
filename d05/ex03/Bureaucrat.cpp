/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:43:16 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 21:53:35 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int const Bureaucrat::maxGrade = 1;
int const Bureaucrat::minGrade = 150;

Bureaucrat::Bureaucrat() : _name("No name"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < maxGrade)
        throw(Bureaucrat::GradeTooHighException());
    if (grade > minGrade)
        throw(Bureaucrat::GradeTooLowException());
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat const & Bureaucrat::operator=(const Bureaucrat & rhs)
{
    if (this != &rhs)
        *this = Bureaucrat(rhs._name, rhs._grade);
    
    return (*this);
}


Bureaucrat::Bureaucrat(Bureaucrat const & other)
{
    *this = other;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade <= maxGrade)
        throw(Bureaucrat::GradeTooHighException());
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade >= minGrade)
        throw(Bureaucrat::GradeTooLowException());
    this->_grade++;
}

std::string const & Bureaucrat::getName() const { return(this->_name); }
int Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
    }
    catch (Form::GradeTooHighException& gradeTooHigh)
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << gradeTooHigh.what() << std::endl;
    }
    catch (Form::GradeTooLowException& gradeTooLow)
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << gradeTooLow.what() << std::endl;
    }
}

void Bureaucrat::executeForm(Form& form)
{
    try
    {
        form.execute(*this);
    }
    catch (Form::NotSignedException& notSigned)
    {
        std::cout << this->_name << " cannot execute " << form.getName() << " because " << notSigned.what() << std::endl;
    }
    catch (Form::GradeTooLowException& gradeTooLow)
    {
        std::cout << this->_name << " cannot execute " << form.getName() << " because " << gradeTooLow.what() << std::endl;
    }   
}

// Exception classes

Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat::GradeTooHighException const & other)
{
    *this = other;
}

Bureaucrat::GradeTooHighException const & Bureaucrat::GradeTooHighException::operator=(const Bureaucrat::GradeTooHighException & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat exception: Grade is too high");
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException const & other)
{
    *this = other;
}

Bureaucrat::GradeTooLowException const & Bureaucrat::GradeTooLowException::operator=(const Bureaucrat::GradeTooLowException & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat exception: Grade is too low");
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (o);
}
