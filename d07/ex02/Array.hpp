/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:46:13 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/08 18:15:40 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {

private:
    unsigned int _numberOfElements;
    T *_array;

public:
    class OutOfRangeException : public std::exception {
    public:
        OutOfRangeException() {}
        ~OutOfRangeException() _NOEXCEPT {}
        OutOfRangeException(OutOfRangeException const & other) { *this = other; }
        OutOfRangeException const & operator=(OutOfRangeException const & rhs)
        {
            static_cast<void>(rhs);
            return (*this);
        }

        virtual const char * what() const throw() { return ("out of Range exception"); }
    };

    Array<T>() { _array = nullptr; _numberOfElements = 0; }

    Array<T>(unsigned int n) { _array = new T[n]; _numberOfElements = n; }

    ~Array<T>() { delete [] _array; }

    Array<T>(Array<T> const & other)
    {
        _array = new T[other.size()];
        _numberOfElements = other.size();
         for (size_t i = 0; i < other.size(); i++)
            _array[i] = other._array[i];
    }

    Array<T> const & operator=(Array<T> const & rhs)
    {
        if (this != &rhs)
        {
            if (_array)
                delete [] _array;
            _array = new T[rhs.size()];
            _numberOfElements = rhs.size();
            for (size_t i = 0; i < rhs.size(); i++)
                _array[i] = rhs._array[i];
        }
        return (*this);
    }

    size_t size() const { return (this->_numberOfElements); }

    T & operator[](unsigned int i)
    {
        if (i >= _numberOfElements || !(_array))
            throw(OutOfRangeException());
        return (_array[i]);
    }
};

#endif