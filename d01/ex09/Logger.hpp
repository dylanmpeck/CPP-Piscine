/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:14:26 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/01 13:14:50 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Logger_h
#define Logger_h

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <time.h>

class Logger {
    
private:
    std::string _logFile;
    
    void logToConsole(std::string message);
    void logToFile(std::string message);
    std::string makeLogEntry(std::string message);
    
public:
    Logger(std::string logName);
    ~Logger();
    void log(std::string const & dest, std::string const & message);
    
};

#endif