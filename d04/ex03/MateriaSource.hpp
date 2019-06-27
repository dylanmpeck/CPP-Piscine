/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:29:57 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/04 12:30:14 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria *_knownMateria[4];
    int      _materiaCount;
    
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(MateriaSource const &);
    MateriaSource const & operator=(MateriaSource const &);
    
    void learnMateria(AMateria * m);
    AMateria *createMateria(std::string const & type);
};

#endif
