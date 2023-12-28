/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_op_overload.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:57:22 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 15:57:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool	Fixed::operator> (const Fixed& other) const
{
	return (raw_bits > other.raw_bits);
}

bool	Fixed::operator< (const Fixed& other) const
{
	return (raw_bits < other.raw_bits);
}

bool	Fixed::operator>= (const Fixed& other) const
{
	return (raw_bits >= other.raw_bits);
}

bool	Fixed::operator<= (const Fixed& other) const
{
	return (raw_bits <= other.raw_bits);
}

bool	Fixed::operator== (const Fixed& other) const
{
	return (raw_bits == other.raw_bits);
}

bool	Fixed::operator!= (const Fixed& other) const
{
	return (raw_bits != other.raw_bits);
}

// member operator overloads (arithmatic operations)

Fixed	Fixed::operator+ (const Fixed& other) const
{
	Fixed sum (this->toFloat() + other.toFloat());
	return (sum);
}

Fixed	Fixed::operator- (const Fixed& other) const
{
	Fixed sum (this->toFloat() - other.toFloat());
	return (sum);
}

Fixed	Fixed::operator* (const Fixed& other) const
{
	Fixed sum (this->toFloat() * other.toFloat());
	return (sum);
}

Fixed	Fixed::operator/ (const Fixed& other) const
{
	Fixed sum (0);
	if (other.raw_bits == 0)
		return (sum);
	sum = this->toFloat() / other.toFloat();
	return (sum);
}

// increment operator overloads (increment/decrement)

Fixed&	Fixed::operator++(void)
{
	++raw_bits;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed copy (*this);

	++(*this);
	return (copy);
}

Fixed&	Fixed::operator--(void)
{
	--raw_bits;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed copy (*this);

	--(*this);
	return (copy);
}
