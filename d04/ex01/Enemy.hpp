/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:08:37 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/03 17:36:43 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy {

private:
    int _hp;
    std::string _type;

protected:
    Enemy();

public:
    Enemy(int hp, std::string const & type);
    virtual ~Enemy();
    Enemy(Enemy const &);
    Enemy & operator=(Enemy const &);
    std::string const & getType() const;
    int getHP() const;

    virtual void takeDamage(int damage);
};

#endif