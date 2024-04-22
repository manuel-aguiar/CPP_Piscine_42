/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:46:51 by manuel            #+#    #+#             */
/*   Updated: 2024/04/22 09:12:13 by codespace        ###   ########.fr       */
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

template <typename T> T& min(T& a, T& b)
{
    return (b > a ? a : b);
}

template <typename T> T& max(T& a, T& b)
{
    return (a > b ? a : b);
}

/*
	Prefer the reference version because, for instance
	in case of a string or some container, i don't want
	to copy it entirely for this functions, best
	to access it via reference
*/

#endif
