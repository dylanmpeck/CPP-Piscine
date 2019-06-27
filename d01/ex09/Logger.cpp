/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:14:13 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/01 13:21:16 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string logName) : _logFile(logName) {}

Logger::~Logger() {}

void Logger::logToConsole(std::string message)
{
    std::cout << message << std::endl;
}

void Logger::logToFile(std::string message)
{
    std::ofstream outFile(this->_logFile, std::ios_base::app);
    if (outFile.fail() || outFile.is_open() == false)
        this->logToConsole("Error: invalid log file name. Log to file didn't happen.");
    else
        outFile << message << std::endl;
}

std::string Logger::makeLogEntry(std::string message)
{
    std::time_t t = std::time(0);
    std::tm *timeStruct = localtime(&t);
    
    std::stringstream ss("", std::ios_base::app | std::ios_base::out);
    ss << timeStruct->tm_year + 1900 << std::setfill('0') << std::setw(2) << timeStruct->tm_mon;
    ss << std::setfill('0') << std::setw(2) << timeStruct->tm_mday << "_";
    ss << std::setfill('0') << std::setw(2) << timeStruct->tm_hour;
    ss << std::setfill('0') << std::setw(2) << timeStruct->tm_min;
    ss << std::setfill('0') << std::setw(2) << timeStruct->tm_sec << " ";
    ss << message;
    return (ss.str());
}

void Logger::log(std::string const & dest, std::string const & message)
{
    std::string destinations[] = {"console", "file"};
    
    typedef void (Logger::*Funcs)(std::string);
    Funcs funcs[] = {&Logger::logToConsole, &Logger::logToFile};
    
    for (int i = 0; i < 2; i++)
    {
        if (destinations[i] == dest)
            (this->*(funcs[i]))(makeLogEntry(message));
    }
}