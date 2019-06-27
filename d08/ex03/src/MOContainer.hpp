/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MOContainer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:57:41 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/10 16:13:32 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOCONTAINER_HPP
#define MOCONTAINER_HPP

#include <algorithm>
#include <string>

class MOContainer {

private:
    char *_data;
    int _position;

public:
    MOContainer();
    ~MOContainer();
    MOContainer const & operator=(MOContainer const &);
    MOContainer(MOContainer const &);

    void setPosition(int pos);
    int getPosition();
    char *getDataAtCurPos();

    static const int _size;
};

#endif