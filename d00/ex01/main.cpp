/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:57:03 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 18:07:54 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Contact.hpp"

void add(Contact contacts[], int index)
{
    std::string input = "";
    std::cout << "Enter contact's first name: ";
    std::getline(std::cin, input);
    contacts[index].setFirstName(input);
    std::cout << "Enter contact's last name: ";
    std::getline(std::cin, input);
    contacts[index].setLastName(input);
    std::cout << "Enter contact's nick name: ";
    std::getline(std::cin, input);
    contacts[index].setNickName(input);
    std::cout << "Enter contact's login: ";
    std::getline(std::cin, input);
    contacts[index].setLogin(input);
    std::cout << "Enter contact's postal address: ";
    std::getline(std::cin, input);
    contacts[index].setAddress(input);
    std::cout << "Enter contact's email address: ";
    std::getline(std::cin, input);
    contacts[index].setEmail(input);
    std::cout << "Enter contact's phone number: ";
    std::getline(std::cin, input);
    contacts[index].setPhoneNumber(input);
    std::cout << "Enter contact's birthday: ";
    std::getline(std::cin, input);
    contacts[index].setBirthdate(input);
    std::cout << "Enter contact's favorite meal: ";
    std::getline(std::cin, input);
    contacts[index].setFavoriteMeal(input);
    std::cout << "Enter contact's underwear color: ";
    std::getline(std::cin, input);
    contacts[index].setUnderwearColor(input);
    std::cout << "Enter contact's darkest secret: ";
    std::getline(std::cin, input);
    contacts[index].setDarkestSecret(input);
}

void printSearchName(std::string name)
{
    if (name.length() > 10)
    {
        for (int i = 0; i < 9; i++)
            std::cout << name[i];
        std::cout << ".|";
    }
    else
    {
        std::cout.width(10);
        std::cout << name;
        std::cout << "|";
    }  
}

void printContactInfo(Contact contact)
{
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nick Name: " << contact.getNickName() << std::endl;
    std::cout << "Login: " << contact.getLogin() << std::endl;
    std::cout << "Postal Address: " << contact.getAddress() << std::endl;
    std::cout << "Email Address: " << contact.getEmail() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Birthday: " << contact.getBirthdate() << std::endl;
    std::cout << "Favorite Meal: " << contact.getFavoriteMeal() << std::endl;
    std::cout << "Underwear Color: " << contact.getUnderwearColor() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void search(Contact contacts[], int index)
{
    std::string name = "";
    std::string entry = "";
    int entryNumber;

    std::cout.setf(std::ios::right);
    for (int i = 0; i < index; i++)
    {
        std::cout.width(10);
        std::cout << i << "|";
        name = contacts[i].getFirstName();
        printSearchName(name);
        name = contacts[i].getLastName();
        printSearchName(name);
        name = contacts[i].getNickName();
        printSearchName(name);
        std::cout << std::endl;
    }
    std::cout.unsetf(std::ios::right);

    std::cout << "Input index of desired entry: ";
    std::getline(std::cin, entry);
    
    for (unsigned long i = 0; i < entry.length(); i++)
    {
        if (!isdigit(entry[i]))
        {
            std::cout << "Invalid input: contact entry is a number." << std::endl;
            return;
        }
    }

    std::istringstream iss(entry);
    iss >> entryNumber;
    if (entryNumber < 0 || entryNumber >= index)
        std::cout << "Invalid input: Contact entry doesn't exist." << std::endl;
    else
        printContactInfo(contacts[entryNumber]);
}

int main()
{
    Contact contacts[8];
    int index = 0;
    bool quit = false;
    std::string input = "";

    std::cout << "Welcome to my phone book!" << std::endl;

    while (quit == false)
    {
        std::cout << "Please input a command (ADD, SEARCH, or EXIT)" << std::endl;
        std::getline(std::cin, input);
        if (input == "EXIT")
            quit = true;
        else if (input == "ADD")
        {
            if (index >= 8)
                std::cout << "Contact list is full. Contact cannot be added." << std::endl;
            else
            {
                add(contacts, index);
                std::cout << "New contact added!" << std::endl;
                index++;
            }
        }
        else if (input == "SEARCH")
        {
            int c_idx = (index < 8) ? index : 8;
            if (c_idx > 0)
                search(contacts, c_idx);
        }
        else
            std::cout << "Invalid input." << std::endl;
    }

    return (0);
}
