/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:32:43 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 22:14:05 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>

class Converter {

private:
    bool _isFloat;
    int _precision;

public:
    Converter();
    ~Converter();
    Converter(Converter const &);
    Converter const & operator=(Converter const &);

    void doConversions(std::string str);
    void convertChar(char c);
    void convertInt(int i);
    void convertFloat(float f);
    void convertDouble(double d);
    void printImpossible();

    bool isDecimal(std::string str);
	bool isScientific(std::string str);
    void getPrecision(std::string str);
};

#endif
