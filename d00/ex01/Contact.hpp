/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:34:47 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 18:06:32 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string login;
    std::string address;
    std::string email;
    std::string phoneNumber;
    std::string birthdate;
    std::string favoriteMeal;
    std::string underwearColor;
    std::string darkestSecret;

public:
    Contact();
    ~Contact();

    void setFirstName(std::string name);
    void setLastName(std::string name);
    void setNickName(std::string name);
    void setLogin(std::string login);
    void setAddress(std::string address);
    void setEmail(std::string email);
    void setPhoneNumber(std::string number);
    void setBirthdate(std::string date);
    void setFavoriteMeal(std::string meal);
    void setUnderwearColor(std::string color);
    void setDarkestSecret(std::string secret);

    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getLogin();
    std::string getAddress();
    std::string getEmail();
    std::string getPhoneNumber();
    std::string getBirthdate();
    std::string getFavoriteMeal();
    std::string getUnderwearColor();
    std::string getDarkestSecret();
};

#endif
