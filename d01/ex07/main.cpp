/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:08:50 by dpeck             #+#    #+#             */
/*   Updated: 2019/04/30 20:10:31 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void findAndReplaceStr(std::string& fileData, std::string const & s1, std::string const & s2)
{
    size_t pos = fileData.find(s1);

    while (pos != std::string::npos)
    {
        fileData.replace(pos, s1.size(), s2);
        pos = fileData.find(s1, pos + s2.size());
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Invalid number of arguments" << std::endl;
        return (1);
    }
    else
    {
        std::ifstream file(argv[1]);
        if (file)
        {
            std::stringstream buffer;
            buffer << file.rdbuf();
            file.close();
            std::string fileData = buffer.str();
            std::string s1 = argv[2];
            std::string s2 = argv[3];
            
            if (fileData.empty())
            {
                std::cout << "File is empty." << std::endl;
                return (1);
            }

            findAndReplaceStr(fileData, s1, s2);
            std::string replaceName = argv[1];
            replaceName += ".replace";
            std::ofstream out(replaceName);
            out << fileData;
            out.close();
        }
        else
            std::cout << "Invalid file." << std::endl;
    }
    return (0);
}