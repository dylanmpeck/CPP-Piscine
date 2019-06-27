/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:45:37 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 18:08:05 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickName(""), 
                    login(""), address(""),  email(""), phoneNumber(""),
                    birthdate(""), favoriteMeal(""), underwearColor(""),
                    darkestSecret("") {}

Contact::~Contact() {}

void Contact::setFirstName(std::string name)
{
    this->firstName = name;
}
    
void Contact::setLastName(std::string name)
{
    this->lastName = name;
}

void Contact::setNickName(std::string name)
{
    this->nickName = name;
}

void Contact::setLogin(std::string login)
{
    this->login = login;
}

void Contact::setAddress(std::string address)
{
    this->address = address;
}

void Contact::setEmail(std::string email)
{
    this->email = email;
}

void Contact::setPhoneNumber(std::string number)
{
    this->phoneNumber = number;
}

void Contact::setBirthdate(std::string date)
{
    this->birthdate = date;
}

void Contact::setFavoriteMeal(std::string meal)
{
    this->favoriteMeal = meal;
}

void Contact::setUnderwearColor(std::string color)
{
    this->underwearColor = color;
}

void Contact::setDarkestSecret(std::string secret)
{
    this->darkestSecret = secret;
}

std::string Contact::getFirstName()
{
    return (this->firstName);
}

std::string Contact::getLastName()
{
    return (this->lastName);
}

std::string Contact::getNickName()
{
    return (this->nickName);
}

std::string Contact::getLogin()
{
    return (this->login);
}

std::string Contact::getAddress()
{
    return (this->address);
}

std::string Contact::getEmail()
{
    return (this->email);
}

std::string Contact::getPhoneNumber()
{
    return (this->phoneNumber);
}

std::string Contact::getBirthdate()
{
    return (this->birthdate);
}

std::string Contact::getFavoriteMeal()
{
    return (this->favoriteMeal);
}

std::string Contact::getUnderwearColor()
{
    return (this->underwearColor);
}

std::string Contact::getDarkestSecret()
{
    return (this->darkestSecret);
}
