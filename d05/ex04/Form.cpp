/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:52:50 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/07 13:23:17 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int Form::maxGrade = 1;
int Form::minGrade = 150;

Form::Form() : _name("No Name"), _gradeRequiredToSign(1), _gradeRequiredToExecute(1)
{
    this->_signed = false;
}

Form::Form(std::string name, int signGrade, int exeGrade) :
            _name(name), _gradeRequiredToSign(signGrade), _gradeRequiredToExecute(exeGrade)
{
    if (_gradeRequiredToExecute > minGrade || _gradeRequiredToSign > minGrade)
        throw(Form::GradeTooLowException());

    if (_gradeRequiredToExecute < maxGrade || _gradeRequiredToSign < maxGrade)
        throw(Form::GradeTooHighException());

    this->_signed = false;
}

Form::Form(std::string name, std::string target, int signGrade, int exeGrade) :
            _name(name), _target(target), _gradeRequiredToSign(signGrade), _gradeRequiredToExecute(exeGrade)
{
    if (_gradeRequiredToExecute > minGrade || _gradeRequiredToSign > minGrade)
        throw(Form::GradeTooLowException());

    if (_gradeRequiredToExecute < maxGrade || _gradeRequiredToSign < maxGrade)
        throw(Form::GradeTooHighException());

    this->_signed = false;
}

Form::~Form() {}

Form const & Form::operator=(Form const & rhs)
{
    if (this != &rhs)
    {
        this->_signed = rhs._signed;
    }
    return (*this);
}

Form::Form(Form const & other) : _name(other._name), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute)
{
    this->_signed = other._signed;
}

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > this->_gradeRequiredToSign)
        throw(GradeTooLowException());
    std::cout << b << " signs a " << *this << " targeted on " << getTarget() << " (Unsigned)" << std::endl;
    this->_signed = true;
}

void Form::execute(Bureaucrat const & executor)
{
    if (this->isSigned() == false)
        throw (NotSignedException());
    if (executor.getGrade() > this->getGradeRequiredtoExecute())
        throw (GradeTooLowException());
    std::cout << executor << " executes a " << *this << " targeted on " << getTarget() << " (Signed)" << std::endl;
    this->beExecuted();
}

std::string const Form::getName() const { return (this->_name); }
std::string const Form::getTarget() const { return (this->_target); }
int Form::getGradeRequiredtoExecute() const { return (this->_gradeRequiredToExecute); }
int Form::getGradeRequiredToSign() const { return (this->_gradeRequiredToSign); }
bool Form::isSigned() const { return (this->_signed); }

// Exception classes:

// GRADETOOHIGH

Form::GradeTooHighException::GradeTooHighException() {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException::GradeTooHighException(Form::GradeTooHighException const & other)
{
    *this = other;
}

Form::GradeTooHighException const & Form::GradeTooHighException::operator=(const Form::GradeTooHighException & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char * Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

//GRADETOOLOW

Form::GradeTooLowException::GradeTooLowException() {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException::GradeTooLowException(Form::GradeTooLowException const & other)
{
    *this = other;
}

Form::GradeTooLowException const & Form::GradeTooLowException::operator=(const Form::GradeTooLowException & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char * Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

// NOTSIGNED

Form::NotSignedException::NotSignedException() {}
Form::NotSignedException::~NotSignedException() throw() {}

Form::NotSignedException::NotSignedException(Form::NotSignedException const & other)
{
    *this = other;
}

Form::NotSignedException const & Form::NotSignedException::operator=(const Form::NotSignedException & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char * Form::NotSignedException::what() const throw()
{
    return ("form isn't signed");
}

// Putto operator for output

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
    o << rhs.getName() << " (s.grade " << rhs.getGradeRequiredToSign() << ", ex.grade " << rhs.getGradeRequiredtoExecute() << ")";
    return (o);
}
