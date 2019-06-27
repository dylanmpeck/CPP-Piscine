/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:01:36 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/06 20:03:19 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"

class Intern {

public:
    Intern();
    ~Intern();
    Intern(Intern const &);
    Intern const & operator=(Intern const &);

    Form * makeForm(std::string name, std::string target);
};

#endif