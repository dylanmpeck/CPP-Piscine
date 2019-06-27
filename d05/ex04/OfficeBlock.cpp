/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:31:40 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/07 13:21:26 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : _intern(NULL), _signBur(NULL), _execBur(NULL) {}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signBur, Bureaucrat *execBur) :
                            _intern(intern), _signBur(signBur), _execBur(execBur) {}

OfficeBlock::~OfficeBlock() {}

OfficeBlock const & OfficeBlock::operator=(OfficeBlock const & rhs)
{
    (void)rhs;
    return (*this);
}

OfficeBlock::OfficeBlock(OfficeBlock const & other)
{
    *this = other;
}

void OfficeBlock::doBureaucracy(std::string name, std::string target)
{
    if (_intern == nullptr || _signBur == nullptr || _execBur == nullptr)
        throw (BlockNotFullException());

    Form *form = nullptr;
    form = _intern->makeForm(name, target);

    if (form == nullptr)
        throw(InvalidFormException());

    std::cout << "Intern creates a " << *form << " targeted on " << target;
    if (form->isSigned())
        std::cout << " (Signed)" << std::endl;
    else
        std::cout << " (Unsigned)" << std::endl;
    
    try
    {
        _signBur->signForm(*form);
    }
    catch (Form::GradeTooLowException& signGradeTooLow)
    {
        std::cout << *_signBur << " cannot sign " << *form << " because " << signGradeTooLow.what() << std::endl;
    }

    try
    {
        _execBur->executeForm(*form);  
    }
    catch(Form::GradeTooLowException& execGradeTooLow)
    {
        std::cout << *_execBur << " cannont execute " << *form << " because " << execGradeTooLow.what() << std::endl;
    }
    catch (Form::NotSignedException& notSigned)
    {
        std::cout << *_execBur << " cannot execute " << *form << " because " << notSigned.what() << std::endl;
    }

	if (form != nullptr)
		delete form;
}

void OfficeBlock::setIntern(Intern *intern) { this->_intern = intern; }
void OfficeBlock::setSigner(Bureaucrat *signBur) { this->_signBur = signBur; }
void OfficeBlock::setExecutor(Bureaucrat *execBur) { this->_execBur = execBur; }

// Exception classes:

// BlockNotFull

OfficeBlock::BlockNotFullException::BlockNotFullException() {}
OfficeBlock::BlockNotFullException::~BlockNotFullException() throw() {}

OfficeBlock::BlockNotFullException::BlockNotFullException(OfficeBlock::BlockNotFullException const & other)
{
    *this = other;
}

OfficeBlock::BlockNotFullException const & OfficeBlock::BlockNotFullException::operator=(const OfficeBlock::BlockNotFullException & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char * OfficeBlock::BlockNotFullException::what() const throw()
{
    return ("Office Block isn't full. Must have intern, signing bureaucrat, and executing bureaucrat.");
}

// INVALIDFORM

OfficeBlock::InvalidFormException::InvalidFormException() {}
OfficeBlock::InvalidFormException::~InvalidFormException() throw() {}

OfficeBlock::InvalidFormException::InvalidFormException(OfficeBlock::InvalidFormException const & other)
{
    *this = other;
}

OfficeBlock::InvalidFormException const & OfficeBlock::InvalidFormException::operator=(const OfficeBlock::InvalidFormException & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char * OfficeBlock::InvalidFormException::what() const throw()
{
    return ("Invalid form name.");
}
