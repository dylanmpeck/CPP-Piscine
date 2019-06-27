/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:27:40 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 12:28:01 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter {
  
private:
    std::string _name;
    AMateria * _equippedMateria[4];

    
protected:
     Character();
    
public:
    Character(std::string name);
    ~Character();
    Character(Character const &);
    Character(ICharacter const &);
    Character const & operator=(Character const &);
    ICharacter const & operator=(ICharacter const & rhs);
    
    std::string const & getName() const;
    void equip(AMateria *);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
