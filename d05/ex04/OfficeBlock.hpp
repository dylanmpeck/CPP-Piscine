/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:26:44 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 21:37:50 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include "Intern.hpp"

class OfficeBlock {

private:
    Intern* _intern;
    Bureaucrat* _signBur;
    Bureaucrat* _execBur;

    OfficeBlock(OfficeBlock const &);
    OfficeBlock const & operator=(OfficeBlock const &); 

public:
    OfficeBlock();
    OfficeBlock(Intern *intern, Bureaucrat *signBur, Bureaucrat *execBur);
    ~OfficeBlock();

    void setIntern(Intern *intern);
    void setSigner(Bureaucrat *signBur);
    void setExecutor(Bureaucrat *execBur);

    void doBureaucracy(std::string name, std::string target);

    class BlockNotFullException : public std::exception {
    public:
        BlockNotFullException();
        ~BlockNotFullException() _NOEXCEPT;
        BlockNotFullException(BlockNotFullException const &);
        BlockNotFullException const & operator=(BlockNotFullException const &);
        
        virtual const char* what() const throw();
    };

    class InvalidFormException : public std::exception {
    public:
        InvalidFormException();
        ~InvalidFormException() _NOEXCEPT;
        InvalidFormException(InvalidFormException const &);
        InvalidFormException const & operator=(InvalidFormException const &);
        
        virtual const char* what() const throw();
    };
};

#endif