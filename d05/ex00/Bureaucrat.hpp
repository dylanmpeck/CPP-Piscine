/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:43:31 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 16:43:51 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <ostream>

class Bureaucrat {
  
private:
    std::string const _name;
    int _grade;
    static const int maxGrade;
    static const int minGrade;
    
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(Bureaucrat const &);
    Bureaucrat const & operator=(Bureaucrat const &);
    
    std::string const & getName() const;
    int getGrade() const;
    
    void incrementGrade();
    void decrementGrade();
    
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

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
