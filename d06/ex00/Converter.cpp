/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:40:18 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 22:20:29 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <cmath>

Converter::Converter() : _isFloat(false), _precision(0) 
{
}

Converter::~Converter() {}

Converter const & Converter::operator=(Converter const & rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

Converter::Converter(Converter const & other)
{
    *this = other;
}

bool Converter::isDecimal(std::string str)
{
	unsigned long it = 0;
    bool decimalPoint = false;
    size_t minSize = 0;
    if(str.size()>0 && (str[0] == '-' || str[0] == '+')){
      it++;
      minSize++;
    }
    while(it < str.length()){
      if(str[it] == '.'){
        if(!decimalPoint) decimalPoint = true;
        else break;
      }else if(!std::isdigit(str[it]) && ((str[it]!='f') || !decimalPoint)){
        break;
      }
      ++it;
    }
    return str.size()>minSize && it == str.length() && decimalPoint;
}

bool Converter::isScientific(std::string str)
{
	unsigned long it = 0;
    bool decimalPoint = false;
	bool negCheck = false;
    size_t minSize = 0;
    if(str.size()>0 && (str[0] == '-' || str[0] == '+')){
      it++;
      minSize++;
    }
    while(it < str.length()){
      if(str[it] == 'e' || str[it] == 'E'){
        if(!decimalPoint) 
		{
			decimalPoint = true;
			negCheck = true;
		}
        else break;
      }
	  else if (str[it] == '-')
	  {
		  if (!negCheck || !decimalPoint)
			  break;
		  negCheck = false;
	  }
	  else if(!std::isdigit(str[it]) && ((str[it]!='f') || !decimalPoint)){
        break;
      }
      ++it;
    }
    return str.size()>minSize && it == str.length() && decimalPoint;
}

void Converter::getPrecision(std::string str)
{
    bool hitDecimal = false;
    bool decimalAtBegin = false;
    int tempPrec = 0;
    int sigDigits = 0;
    int tempSigDigits = 0;

    if (str[0] == '.')
        decimalAtBegin = true;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            hitDecimal = true;
		else if (str[i] == 'e' || str[i] == 'E')
		{
			if (i + 1 < str.length())
			{
				if (str[i + 1] == '-')
				{
					if (i + 2 < str.length())
					{
						char *tempStr = &str[i + 2];
						_precision = std::atoi(tempStr);
						return;
					}
				}
				else
				{
					_precision = 1;
					return;
				}
			}
		}
        else if (decimalAtBegin == true && str[i] == '0')
            tempPrec++;
        else if (decimalAtBegin == true)
        {
            decimalAtBegin = false;
            _precision++;
        }
        else if (hitDecimal == true)
        {
            sigDigits++;
            _precision++;
        }
        else if (hitDecimal == false && str[i] == '0')
            tempSigDigits++;
        else if (hitDecimal == false)
        {
            sigDigits++;
            sigDigits += tempSigDigits;
            tempSigDigits = 0;
        }
    }

    if (decimalAtBegin == true)
        _precision += tempPrec;

    if (sigDigits <= 7)
        this->_isFloat = true;   
}

void Converter::doConversions(std::string arg)
{
    getPrecision(arg);
    if (arg.length() == 1)
    {
        if (arg[0] >= '0' && arg[0] <= '9')
            convertInt(std::stoi(arg.c_str()));
        else
            convertChar(arg[0]);
    }
    else
    {
        if (isDecimal(arg) || isScientific(arg))
        {
            if (_isFloat == true)
            {
                try{
                    convertFloat(std::stof(arg, 0));
                } catch (std::exception& e)
                {
                    try {
                        convertDouble(std::stod(arg, 0));
                    } catch (std::exception& eD)
                    {
                        printImpossible();
                    }
                }
            }
            else
            {
                try{
                    convertDouble(std::stod(arg, 0));
                }
                catch (std::exception& e)
                {
                    printImpossible();
                }
            }
        }
        else
        {
            try {
                convertInt(std::stoi(arg, 0, 10));
            }
            catch (std::exception& e)
            {
                try {
                    convertDouble(std::stod(arg, 0));
                }
                catch (std::exception& eD)
                {
                    printImpossible();
                }
            }
        }
    }
}

void Converter::convertChar(char c)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(this->_precision);
    std::cout << "char: " << "'" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void Converter::convertInt(int i)
{

    std::cout << std::fixed;
    std::cout << std::setprecision(this->_precision);
    std::cout << "char: ";
    if (i < CHAR_MIN || i > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (i <= 31 || i >= 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    
    std::cout << "int: " << i << std::endl;

    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    
}

void Converter::convertFloat(float f)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(this->_precision);

    std::cout << "char: ";
    if (f < CHAR_MIN || f > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (f <= 31 || f >= 127)
        std::cout << "Non Displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    
    std::cout << "int: ";
    if (f < INT_MIN || f > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;
    
    std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void Converter::convertDouble(double d)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(this->_precision);

    std::cout << "char: ";
    if (d < CHAR_MIN || d > CHAR_MAX || isnan(d))
        std::cout << "impossible" << std::endl;
    else if (d <= 31 || d >= 127)
        std::cout << "Non Displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (d < INT_MIN || d > INT_MAX || isnan(d))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}

void Converter::printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
