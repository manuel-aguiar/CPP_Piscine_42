/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:44:11 by manuel            #+#    #+#             */
/*   Updated: 2024/04/24 16:12:26 by codespace        ###   ########.fr       */
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

template <
	class T,
	class F
>
F iter(T arr[], size_t len, F func)
{
	std::cout << "function template copy" << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
	return (func);
}

template <
	class T,
	template <
		typename
	> class F
>
F<T> iter(T arr[], size_t len, F<T> func)
{
	std::cout << "function template template copy" << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
	return (func);
}

template <
	class T,
	class F
>
F& iter(T arr[], size_t len, F* func)
{
	std::cout << "function pointer template" << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        (*func)(arr[i]);
    }
	return (*func);
}

template <
	class T,
	template <
		typename
	> class F
>
F<T>& iter(T arr[], size_t len, F<T>* func)
{
	std::cout << "function template template pointer" << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        (*func)(arr[i]);
    }
	return (*func);
}

template <
	class T,
	class F,
	size_t len
>
F iter(T (&arr)[len], F func)
{
	std::cout << "function copy template, len implicitely passed via &arr reference" << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
	return (func);
}

template <
	class T,
	template <
		typename
	> class F,
	size_t len
>
F<T> iter(T (&arr)[len], F<T> func)
{
	std::cout << "function template template copy, len implicitely passed via &arr reference" << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
	return (func);
}

template <
	class T,
	class F,
	size_t len
>
F& iter(T (&arr)[len], F* func)
{
	std::cout << "function pointer template, len implicitely passed via &arr reference" << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        (*func)(arr[i]);
    }
	return (*func);
}

template <
	class T,
	template <
		typename
	> class F,
	size_t len
>
F<T>& iter(T (&arr)[len], F<T>* func)
{
	std::cout << "function template template pointer, len implicitely passed via &arr reference" << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        (*func)(arr[i]);
    }
	return (*func);
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
