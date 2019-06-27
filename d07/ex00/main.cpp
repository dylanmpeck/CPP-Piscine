/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:20:44 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 15:38:08 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template < typename T >
void swap(T & lhs, T & rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

template < typename T >
T const & min(T const & lhs, T const & rhs)
{
    return (lhs <= rhs ? lhs : rhs);
}

template < typename T >
T const & max(T const & lhs, T const & rhs)
{
    return (lhs >= rhs ? lhs : rhs);
}

int main()
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return (0);
}
