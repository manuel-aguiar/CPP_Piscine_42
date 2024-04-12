/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:46:51 by manuel            #+#    #+#             */
/*   Updated: 2024/04/12 16:49:16 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP

# define WHATEVER_HPP

template <typename T> void swap(T& a, T& b)
{
    T temp;

    temp = a;
    a = b;
    b = temp;
}

template <typename T> T min(T a, T b)
{
    return (b > a ? a : b);
}

template <typename T> T max(T a, T b)
{
    return (a > b ? a : b);
}

#endif