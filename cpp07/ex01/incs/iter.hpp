/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:44:11 by manuel            #+#    #+#             */
/*   Updated: 2024/04/12 17:04:49 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP

# define ITER_HPP

#include <iostream>

template <typename T> void iter(T arr[], size_t len, void(*func)(T&))
{
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

template <typename T> void print_arr(T arr[], size_t len)
{
    for (size_t i = 0; i < len; i++)
        std::cout << arr[i] << "  ";
    std::cout << std::endl;
}

template <typename T> void double_val(T& a)
{
    a = a * 2;
}

template <typename T> void print_cout(T& a)
{
    std::cout << a << std::endl;
}

#endif