/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:27:04 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 12:27:23 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
  
private:
    unsigned int _xp;
    std::string _type;
    
protected:
    AMateria();
    
public:
    AMateria(std::string const & type);
    virtual ~AMateria();
    AMateria(AMateria const &);
    AMateria const & operator=(AMateria const &);
    
    std::string const & getType() const; //Returns the materia type
    unsigned int getXP() const; //Returns the Materia's XP
    void setType(std::string const &);
    void setXP(unsigned int);
    
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
