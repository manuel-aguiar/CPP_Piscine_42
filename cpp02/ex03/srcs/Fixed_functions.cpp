/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_functions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:32:18 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 15:36:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

float   Fixed::toFloat( void ) const
{
    return ((float)raw_bits / (1 << frac_bits));
}

int     Fixed::toInt( void ) const
{
    return (raw_bits >> frac_bits);
}

//public static member functions

Fixed&	Fixed::min(Fixed& first, Fixed& second)
{
	return (first > second ? second : first);
}

const Fixed&	Fixed::min(const Fixed& first, const Fixed& second)
{
	return (first > second ? second : first);
}

Fixed&	Fixed::max(Fixed& first, Fixed& second)
{
	return (first < second ? second : first);
}

const Fixed&	Fixed::max(const Fixed& first, const Fixed& second)
{
	return (first < second ? second : first);
}

Fixed	Fixed::abs(const Fixed& target)
{
	return (target > 0 ? target : target * (-1));
}

// non-member function overload

std::ostream& operator<<(std::ostream& out, const Fixed& num)
{
	out << num.toFloat();
	return (out);
}
