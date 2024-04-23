/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:44:11 by manuel            #+#    #+#             */
/*   Updated: 2024/04/23 11:41:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP

# define ITER_HPP

#include <iostream>

/*
original solution

template <class T>
void iter(T arr[], size_t len, void(*func)(T&))
{
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}
*/

template <class T, class F>
F iter(T arr[], size_t len, F func)
{
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
	return (func);
}

/*
	returning the function object itself, as std::for_each does
*/

template <class T>
void print_arr(T arr[], size_t len)
{
    for (size_t i = 0; i < len; i++)
        std::cout << arr[i] << "  ";
    std::cout << std::endl;
}

template <class T>
void double_val(T& a)
{
    a = a * 2;
}

template <class T>
void print_cout(T& a)
{
    std::cout << a << std::endl;
}

#endif
