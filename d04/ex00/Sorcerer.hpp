/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:24:58 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 15:55:03 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include <string>
#include <ostream>
#include "Victim.hpp"

class Sorcerer {

private:
    std::string _name;
    std::string _title;

    Sorcerer();

public:
    Sorcerer(std::string name, std::string title);
    ~Sorcerer();
    Sorcerer(Sorcerer const & other);
    Sorcerer & operator=(Sorcerer const & other);

    void introduce();
    void polymorph(Victim const &) const;
    std::string getName() const;
    std::string getTitle() const;
};

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs);

#endif