/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:46:43 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 16:22:55 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>
#include <string>
#include <ostream>

class Victim {

private:
    std::string _name;

protected:
    Victim();

public:
    Victim(std::string name);
    ~Victim();
    Victim(Victim const &);
    Victim & operator=(Victim const &);

    void introduce();
    std::string getName() const;
    virtual void getPolymorphed() const;   
};

std::ostream & operator<<(std::ostream & o, Victim const & rhs);

#endif