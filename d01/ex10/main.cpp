/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:13:41 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/01 14:28:55 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

void stdInLoop()
{
    while (1)
    {
        std::string input;
        std::getline(std::cin, input);
        std::cout << input << std::endl;
    }
}

void printError(std::string exeName, std::string fileName, std::string error)
{
    std::cout << exeName << ": " << fileName << ": " << error << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        stdInLoop();
    else
    {
        for (int i = 1; i < argc; i++)
        {
            struct stat st;
            lstat(argv[i], &st);
            if (S_ISDIR(st.st_mode))
            {
                printError(argv[0], argv[i], "Is a directory");
                continue;
            }
            else
            {
                bool newLineAtEnd = false;
                std::string curArg = argv[i];
                if (curArg == "-")
                    stdInLoop();
                std::ifstream checkFile(curArg);
                if (checkFile.fail() || checkFile.bad() || checkFile.eof() || checkFile.is_open() == false)
                {
                    printError(argv[0], curArg, strerror(errno));
                    continue;
                }
                checkFile.seekg(-1, std::ios_base::end);
                char c;
                checkFile.get(c);
                if (c == '\n')
                    newLineAtEnd = true;
                checkFile.close();
                
                std::ifstream file(curArg);
                std::string line;

                while (std::getline(file, line))
                {
                    if (file.eof() && newLineAtEnd == false && i == argc - 1)
                        std::cout << line << "\033[7;1m%\033[0m" << std::endl;
                    else if (file.eof() && newLineAtEnd == false)
                        std::cout << line;
                    else
                        std::cout << line << std::endl;
                }
                file.close();
            }
        }
    }
    return 0;
}