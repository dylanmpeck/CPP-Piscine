/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <dpeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:00:16 by dpeck             #+#    #+#             */
/*   Updated: 2019/05/09 17:20:44 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <utility>

template <typename T>
class MutantStack : public std::stack<T> {

public:
    MutantStack() {}
    ~MutantStack() {}

    MutantStack const & operator=(MutantStack const & rhs) { std::stack<T>::operator=(rhs); return (*this); }

    MutantStack(MutantStack const & other) { *this = other; }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return std::begin(std::stack<T>::c); }
    iterator end() { return std::end(std::stack<T>::c); }

    const_iterator begin() const { return std::begin(std::stack<T>::c); }
    const_iterator end() const { return std::begin(std::stack<T>::c); }
};

#endif