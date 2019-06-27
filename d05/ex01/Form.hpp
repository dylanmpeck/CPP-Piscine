/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:45:47 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 17:35:45 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
    std::string const _name;
    bool _signed;
    int  const _gradeRequiredToSign;
    int  const _gradeRequiredToExecute;
    static int minGrade;
    static int maxGrade;
    Form();

public:
    Form(std::string name, int signGrade, int exeGrade);
    ~Form();
    Form(Form const &);
    Form const & operator=(Form const &);

    std::string const getName() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredtoExecute() const;
    bool isSigned() const;

    void beSigned(Bureaucrat &b);

    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException();
        ~GradeTooHighException() _NOEXCEPT;
        GradeTooHighException(GradeTooHighException const &);
        GradeTooHighException const & operator=(GradeTooHighException const &);
        
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        GradeTooLowException();
        ~GradeTooLowException() _NOEXCEPT;
        GradeTooLowException(GradeTooLowException const &);
        GradeTooLowException const & operator=(GradeTooLowException const &);
        
        virtual const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif